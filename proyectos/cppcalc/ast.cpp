#include "ast.h"
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include "calculator.h"

// for debug information uncomment
//#define debug

AST::AST() {}

AST::~AST() {}

BinaryNode::BinaryNode(AST* left, AST* right):
   AST(),
   leftTree(left),
   rightTree(right)
{}

BinaryNode::~BinaryNode()
{
#ifdef debug
   cout << "In BinaryNode destructor" << endl;
#endif

   try
   {
      delete leftTree;
   } catch (...) {}

   try
   {
      delete rightTree;
   } catch(...) {}
}

AST* BinaryNode::getLeftSubTree() const
{
   return leftTree;
}

AST* BinaryNode::getRightSubTree() const
{
   return rightTree;
}

UnaryNode::UnaryNode(AST* sub):
   AST(),
   subTree(sub)
{}

UnaryNode::~UnaryNode()
{
#ifdef debug
   cout << "In UnaryNode destructor" << endl;
#endif

   try
   {
      delete subTree;
   } catch (...) {}
}

AST* UnaryNode::getSubTree() const
{
   return subTree;
}



AddNode::AddNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int AddNode::evaluate()
{
   return getLeftSubTree()->evaluate() + getRightSubTree()->evaluate();
}

string AddNode::compileEWE()
{
  string linea = getLeftSubTree()->compileEWE()+getRightSubTree()->compileEWE();
  return linea +"# Add \noperator2 := M[sp+0]\n\toperator1 := M[sp+1]\n\toperator1 := operator1 + operator2\n\tsp := sp + one\n\tM[sp+0] := operator1\n";
}



SubNode::SubNode(AST* left, AST* right):
   BinaryNode(left,right)
{}

int SubNode::evaluate()
{
   return getLeftSubTree()->evaluate() - getRightSubTree()->evaluate();
}

string SubNode::compileEWE()
{
  string linea = getLeftSubTree()->compileEWE()+getRightSubTree()->compileEWE();
  return linea +"# Sub\n\toperator2 := M[sp+0]\n\toperator1 := M[sp+1]\n\toperator1 := operator1 - operator2\n\tsp := sp + one\n\tM[sp+0] := operator1\n";
}



TimesNode::TimesNode(AST* left, AST* right):
  BinaryNode(left,right)
{}

int TimesNode::evaluate()
{
  return getLeftSubTree()->evaluate() * getRightSubTree()->evaluate();
}

string TimesNode::compileEWE()
{
  string linea = getLeftSubTree()->compileEWE() + getRightSubTree()->compileEWE();
  return linea +"# Times\n\toperator2 := M[sp+0]\n\toperator1 := M[sp+1]\n\toperator1 := operator1 * operator2\n\tsp := sp + one\n\tM[sp+0] := operator1\n";
}



DivideNode::DivideNode(AST* left, AST* right):
  BinaryNode(left,right)
{}

int DivideNode::evaluate()
{
  return getLeftSubTree()->evaluate() / getRightSubTree()->evaluate();
}

string DivideNode::compileEWE()
{
  string linea = getLeftSubTree()->compileEWE() + getRightSubTree()->compileEWE();
  return linea+ "# Divide\n\toperator2 := M[sp+0]\n\toperator1 := M[sp+1]\n\toperator1 := operator1 / operator2\n\tsp := sp + one\n\tM[sp+0] := operator1\n";
}



ModNode::ModNode(AST* left, AST* right):
  BinaryNode(left,right)
{}

int ModNode::evaluate()
{
  return getLeftSubTree()->evaluate() % getRightSubTree()->evaluate();
}

string ModNode::compileEWE()
{
  string linea = getLeftSubTree()->compileEWE() + getRightSubTree()->compileEWE();
  return linea + "# Module\n\toperator2 := M[sp+0]\n\toperator1 := M[sp+1]\n\toperator1 := operator1 % operator2\n\tsp := sp + one\n\tM[sp+0] := operator1\n";
}



NumNode::NumNode(int n) :
   AST(),
   val(n)
{}

int NumNode::evaluate()
{
   return val;
}

string NumNode::compileEWE()
{
  std::string cadena = "";
  cadena = static_cast<std::ostringstream*>(&(std::ostringstream() << val ))->str();
  return "# push("+cadena+")\n\tsp := sp - one\n\toperator1 := "+cadena+"\n\tM[sp+0] := operator1\n";
}



StoreNode::StoreNode(AST* sub): UnaryNode(sub){}

StoreNode::~StoreNode(){}

int StoreNode::evaluate()
{
  int result = getSubTree() -> evaluate();
  calc->store(result);
  return result;
}

string StoreNode::compileEWE()
{
  calc->store(getSubTree()->evaluate());
  string linea = getSubTree()->compileEWE();
  return linea +"# Store\n\tmemory := M[sp+0]\n";
}



RecallNode::RecallNode() :AST(){}

RecallNode::~RecallNode(){}

int
RecallNode::evaluate()
{
  return calc->recall();
}

string RecallNode::compileEWE()
{
  return "# Recall\n\tsp := sp - one\n\tM[sp+0] := memory\n";
}



IdentifierNode::IdentifierNode(string id):
  AST(), id(id)
{}

int IdentifierNode::evaluate()
{
  return calc->getValue(id);
}

string IdentifierNode::compileEWE()
{
  if(calc->getValue(id) == 0){
    calc->setValue(id,0);
  }
  return "# push("+id+")\n\tsp := sp - one\n\toperator1 := "+id+"\n\tM[sp+0] := operator1\n";
}



AssignationNode::AssignationNode(AST* sub, string id):
  UnaryNode(sub), id(id)
{}

int AssignationNode::evaluate()
{
  int result = getSubTree()->evaluate();
  calc->setValue(id,result);
  calc->setAssignation(id+"<-");
  return result;
}

string AssignationNode::compileEWE()
{
  string linea = getSubTree()->compileEWE();
  calc->setValue(id,getSubTree()->evaluate());
  return linea +"# Assign\n\t"+id+" := M[sp+0]\n";
}



NegativeNode::NegativeNode(AST* sub):
  UnaryNode(sub)
{}

int NegativeNode::evaluate()
{
  return (-1)*(getSubTree()->evaluate());
}

string NegativeNode::compileEWE()
{
  string linea = getSubTree()->compileEWE();
  return linea +"# Negative\n\toperator1 := M[sp+0]\n\toperator1 := zero - operator1\n\tM[sp+0] := operator1\n";
}



MinusNode::MinusNode(AST* sub):
  UnaryNode(sub)
{}
int MinusNode::evaluate()
{
  calc->minus(getSubTree()->evaluate());
  return calc->recall();
}
string MinusNode::compileEWE()
{
  calc->minus(getSubTree()->evaluate());
  string linea = getSubTree()->compileEWE();
  return linea +"# Memory Minus\n\toperator2 := M[sp+0]\n\tmemory := memory - operator2\n\tM[sp+0] := memory\n";
}


PlusNode::PlusNode(AST* sub):
  UnaryNode(sub)
{}

int PlusNode::evaluate()
{
  calc->plus(getSubTree()->evaluate());
  return calc->recall();
}

string PlusNode::compileEWE()
{
  calc->plus(getSubTree()->evaluate());
  string linea = getSubTree()->compileEWE();
  return linea +"# Memory Minus\n\toperator2 := M[sp+0]\n\tmemory := memory + operator2\n\tM[sp+0] := memory\n";
}



CleanNode::CleanNode(): AST() { }
CleanNode::~CleanNode() { }
int CleanNode::evaluate()
{
  calc->clean();
  return calc->recall();
}
string CleanNode::compileEWE()
{
  return "# Clear\n\tmemory := zero\n\tsp := sp - one\n\tM[sp+0] := memory\n";
}
