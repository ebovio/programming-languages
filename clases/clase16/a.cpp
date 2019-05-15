#include "a.h"

A::A(){
  a = 0;
}

A::A(int a) : a(a) { }

A::~A(){ }

int A::getA() const {
  return a;
}

void A::setA(int a) {
  this->a = a;
}
 
