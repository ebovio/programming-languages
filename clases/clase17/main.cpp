#include "a.h"
#include <iostream>

using namespace std;

A global(60);

int
main(void) {
  A unA, otroA(10);

  {
    A *p = &otroA;

    p->setA(20);
  }

  A *po;

  {
    po = new A(unA);

    po->setA(40);
  }
  
  cout << "po->a=" << po->getA()
       << endl; 
  cout << "unA.a" << unA.getA()
       << endl;
  cout << "otroA.a=" << otroA.getA()
       << endl;
  return 0;
}
