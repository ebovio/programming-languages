#include "calculator.h"
#include "parser.h"
#include "ast.h"
#include "calcex.h"
#include "scanner.h"
#include <string>
#include <iostream>
#include <sstream>
#include <map>

Calculator::Calculator():
   memory(0), assignation("")
{}

int Calculator::eval(string expr)
{
   Parser* parser = new Parser(new istringstream(expr));

   AST* tree = parser->parse();

   int result = tree->evaluate();

   delete tree;

   delete parser;

   return result;
}

void Calculator::store(int val)
{
   memory = val;
}

int Calculator::recall()
{
   return memory;
}

void Calculator::clean()
{
  memory = 0;
}

void Calculator::minus(int val){
  memory -= val;
}

void Calculator::plus(int val){
  memory += val;
}

void Calculator::assign(string expr)
{
  Scanner* scan =  new Scanner(new istringstream(expr));
  int var = 1;
  Token* token = scan->getToken();
  if (token->getType() == identifier)
  {
    Token* tokenDos = scan->getToken();
    if (tokenDos->getType() == igual){
      Token* tokent = scan->getToken();
      if (tokent->getType() == sub){
  	    var = -1;
      }else{
  	    scan->putBackToken();
      }

      tokenDos = scan->getToken();
      if (tokenDos->getType() == number){
  	    istringstream in(tokenDos->getLex());
  	    int val;
  	    in >> val;
  	    setValue(token->getLex(),val* var);
      }else{
  	    cerr << "Error: Invalid Command Line" << endl;
  	    throw InvalidCommand;
      }
    }else{
      cerr << "Error: Invalid Command Line" << endl;
      throw InvalidCommand;
    }
  }else{
    cerr << "Error: Invalid Command Line" << endl;
    throw InvalidCommand;
  }
  delete scan;
}

void Calculator::setValue(string id, int value)
{
  identifiers[id] = value;
}

int Calculator::getValue(string id)
{
  if (identifiers.count(id) < 1){
    return 0;
  }
  else
    return identifiers[id];
}

void Calculator::setAssignation(string identifier)
{
  assignation = identifier;
}

string Calculator::getAssignation(){
  return assignation;
}

string Calculator::compileEWE(string expr){
  string expr1 = expr;
  if (expr == "\n") expr1= "";
  string valor = "";
  valor = static_cast<std::ostringstream*>(&(std::ostringstream() << memory ))->str();
  string inicio = " # Expresion "+expr1+":\n # Instrucciones antes del recorrido del arbol abstracto sintactico\nsp := 1000\none := 1\nzero := 0\nmemory := "+valor+"\n";
  string variables = "";

  string n="";
  valor = "";

  for (std::map<string,int>::iterator it = identifiers.begin();
       it != identifiers.end(); ++it) {
    valor = "";
    n = it->first;
    valor = static_cast<std::ostringstream*>(&(std::ostringstream() << it->second ))->str();
    variables = variables+""+n+" := "+valor+"\n";
  }

  inicio =  inicio+variables+ " # Comienza el recorrido del arbol en posorden\n";

  Parser* parser = new Parser(new istringstream(expr));

  AST* tree = parser->parse();

  string result = tree->compileEWE();

  delete tree;

  delete parser;

  return inicio+result+ " # Write Result\noperator1 := M[sp+0]\nsp := sp - one\nwriteInt(operator1)\n";
}

string Calculator::finalCompileEWE(){

  string final = " end: halt\nequ memory M[0]\nequ one M[1]\nequ zero M[2]\nequ operator1 M[3]\nequ operator2 M[4]\nequ sp M[5]\n";
  string variables = "";
  string n = "";
  int v;
  int acum = 6;
  string valor = "";
  for (std::map<string,int>::iterator it = identifiers.begin();
       it != identifiers.end(); ++it) {
    valor = "";
    n = it->first;
    v = it->second;
    valor = static_cast<std::ostringstream*>(&(std::ostringstream() << acum ))->str();
    variables = variables+"equ "+n+"    M["+valor+"]\n";
    acum++;
  }

  return final + variables+"equ stack    M[1000]\n";
}
