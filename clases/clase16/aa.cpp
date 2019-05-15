#include "a.h"
#include <iostream>

using namespace std;

A::A(){
  cout << "Invocando A::A()" << endl;
  a = 0;
}

A::A(int a) : a(a) {
  cout << "Invocando A::A(int)" << endl;
}

A::~A(){
  cout << "Invocando A::~A()" << endl;
}

int A::getA() const {
  return a;
}

void A::setA(int a) {
  this->a = a;
}
 
