#pragma once

class A{
 public:
  A();
  A(int);
  ~A();
  int getA() const;
  void setA(int a);
 private:
  int a;
};
