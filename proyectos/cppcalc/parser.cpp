#include "parser.h"
#include "calcex.h"
#include <string>
#include <sstream>

Parser::Parser(istream* in) {
  scan = new Scanner(in);
}

Parser::~Parser() {
  try {
    delete scan;
  } catch (...) {}
}

AST* Parser::parse() {
  return prog();
}

AST* Parser::prog(){
  AST* result = lineas(linea());
  Token* t = scan->getToken();

  if (t->getType() != eof){
    cerr << "* Parser Error";
    throw ParseError;
  }

  return result;
}


AST* Parser::lineas(AST* l){

  Token* t = scan->getToken();
    if (t->getType() == nuevalinea){
      return  lineas(linea());
    }

    scan->putBackToken();
    return l;
}

AST* Parser::linea(){
  Token* t= scan->getToken();
  if (t->getType() == keyword){
    if (t->getLex() == "let"){
      return assignable();
    }
  }
  if (t->getType() == nuevalinea){
    return new NumNode(0);
  }
    scan->putBackToken();
    return expr();
}


AST* Parser::assignable(){
  Token* t = scan->getToken();
  if (t->getType() == identifier){
    Token* t1 = scan->getToken();
    if(t1->getType() == igual){
      return new AssignationNode(expr(), t->getLex());
    }
    cerr << "* Parser Error\n";
    throw ParseError;
  }
  cerr << "* Parser Error\n";
  throw ParseError;
}



AST* Parser::expr(){
  return restExpr(term());
}




AST* Parser::restExpr(AST* e){
  Token* t = scan->getToken();

  if(t->getType() == add){
    return restExpr(new AddNode(e,term()));
  }
  if(t->getType() == sub){
    return restExpr(new SubNode(e,term()));
  }

  scan->putBackToken();
  return e;
}


AST* Parser::term(){
  return restTerm(storable());
}

AST* Parser::restTerm(AST* e){
  Token* t = scan->getToken();
  if(t->getType() == times){
    return restTerm(new TimesNode(e, storable()));
  }
  if(t->getType() == divide){
    return restTerm(new DivideNode(e, storable()));
  }
  if(t->getType() == mod){
    return restTerm(new ModNode(e, storable()));
  }
  scan->putBackToken();
  return e;
}

AST* Parser::storable(){
  return memOperation(negative());
}

AST* Parser::negative(){
  Token* t = scan->getToken();
  if (t->getType() == sub){
    return new NegativeNode(factor());
  }

  scan->putBackToken();
  return factor();
}

AST* Parser::memOperation(AST* rest){
  Token* t = scan->getToken();

  if(t->getType() == keyword){
    string lexema = t->getLex();
    if(lexema == "S"){
      return new StoreNode(rest);
    }
    if(lexema == "M"){
      return new MinusNode(rest);
    }
    if(lexema == "P"){
      return new PlusNode(rest);
    }
    cerr << "* Parser Error\n";
    throw ParseError;
  }

  scan->putBackToken();
  return rest;
}

AST* Parser::factor(){
  Token* t =scan->getToken();

  if(t->getType() == number){
    istringstream in(t->getLex());
    int val;
    in >> val;
    return new NumNode(val);
  }
  if(t->getType() == keyword){

    string lexema = t->getLex();
    if(lexema == "R"){
      return new RecallNode();
    }
    if(lexema == "C"){
      return new CleanNode();
    }
    cerr << "* Parser Error\n";
    throw ParseError;
  }

  if(t->getType() == identifier){
    return new IdentifierNode(t->getLex());
  }

  if(t->getType() == lparen){
    AST* rest = expr();
    t = scan->getToken();
    if (t->getType() == rparen){
      return rest;
    }
    cerr << "* Parser Error\n";
    throw ParseError;
  }
  cerr << "* Parser Error\n";
  throw ParseError;
}
