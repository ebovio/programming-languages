#pragma once
#include <string>

using namespace std;

class AST
{
 public:
   AST();
   virtual ~AST() = 0;
   virtual int evaluate() = 0;
   virtual string compileEWE() = 0;
};

class BinaryNode : public AST
{
 public:
   BinaryNode(AST* left, AST* right);
   ~BinaryNode();

   AST* getLeftSubTree() const;
   AST* getRightSubTree() const;

 private:
   AST* leftTree;
   AST* rightTree;
};

class UnaryNode : public AST
{
 public:
   UnaryNode(AST* sub);
   ~UnaryNode();

   AST* getSubTree() const;

 private:
   AST* subTree;
};

class AddNode : public BinaryNode
{
 public:
   AddNode(AST* left, AST* right);
   int evaluate();
   string compileEWE();
};

class SubNode : public BinaryNode
{
 public:
   SubNode(AST* left, AST* right);
   int evaluate();
   string compileEWE();
};

class NumNode : public AST
{
  public:
   NumNode(int n);
   int evaluate();
   string compileEWE();
  private:
   int val;
};

class TimesNode : public BinaryNode
{
  public:
   TimesNode(AST* left, AST* right);
   int evaluate();
   string compileEWE();
};

class DivideNode : public BinaryNode
{
  public:
   DivideNode(AST* left, AST* right);
   int evaluate();
   string compileEWE();
};

class ModNode : public BinaryNode
{
  public:
   ModNode(AST* left, AST* right);
   int evaluate();
   string compileEWE();
};

class StoreNode : public UnaryNode
{
  public:
   StoreNode(AST* sub);
   ~StoreNode();
   int evaluate();
   string compileEWE();
};

class RecallNode : public AST
{
  public:
   RecallNode();
   ~RecallNode();
   int evaluate();
   string compileEWE();
};

class CleanNode: public AST
{
 public:
  CleanNode();
  ~CleanNode();

  string compileEWE();
  int evaluate();
};


class AssignationNode: public UnaryNode
{
 public:
  AssignationNode(AST* sub, string id);
  string compileEWE();
  int evaluate();
 private:
  string id;
};


class NegativeNode: public UnaryNode
{
 public:
  NegativeNode(AST* sub);
  string compileEWE();
  int evaluate();
};



class IdentifierNode: public AST {
 public:
  IdentifierNode(string id);

  string compileEWE();
  int evaluate();
 private:
  string id;
};



class MinusNode: public UnaryNode{
 public:
  MinusNode(AST* sub);

  string compileEWE();
  int evaluate();
};



class PlusNode: public UnaryNode{
 public:
  PlusNode(AST* sub);

  string compileEWE();
  int evaluate();
};
