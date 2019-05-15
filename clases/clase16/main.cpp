#include "a.h"
#include <iostream>

using namespace std;

A global(60);

int
main(void) {
  A unA, otroA(10);

  {
    A otroA(otroA);
  }
  cout << "unA.a" << unA.getA()
       << endl;
  cout << "otroA.a=" << otroA.getA()
       << endl;
  return 0;
}
