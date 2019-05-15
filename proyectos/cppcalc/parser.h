#pragma once
#include "ast.h"
#include "scanner.h"

class Parser
{
 public:
   Parser(istream* in);
   ~Parser();

   AST* parse();

private:
   AST* prog();
   AST* prog2();
   AST* expr();
   AST* restExpr(AST* e);
   AST* lineas(AST* l);            
   AST* linea();
   AST* term();
   AST* restTerm(AST* t);
   AST* storable();
   AST* factor();
   AST* memOperation(AST* rest);
   AST* assignable();
   AST* negative();
   Scanner* scan;
};
