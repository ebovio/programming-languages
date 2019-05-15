#pragma once

#include <iostream>
#include <map>
#include <string>

using namespace std;


class Calculator
{
 public:
   Calculator();

   int eval(string expr);
   void store(int val);
   int recall();
   void clean();
   void minus(int val);
   void plus(int val);
   void assign(string expr);
   void setValue(string id, int value);
   int getValue(string id);
   void setAssignation(string identifier);
   string getAssignation();
   string compileEWE(string expr);
   string finalCompileEWE();

 private:
   int memory;
   map<string,int> identifiers;
   string assignation;
};

extern Calculator* calc;
