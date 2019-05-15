/*
 * fichero: Referencias-05.cpp
 *
 * compilar: $ g++ -o Referencias-05 Referencias-05.cpp
 *           $ make Referencias-05
 *
 * ejecutar: $ ./Referencias-05
 */
#include <iostream>

using namespace std;

void
intercambio(int x, int y) {
  int tmp = x;
  x = y;
  y = tmp;
}

void
intercambio2(int* x, int* y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

void
intercambio2(int& x, int& y) {
  int tmp = x;
  x = y;
  y = tmp;
}

int
main() {
  int x = 10;
  int y = 20;
  
  cout << "x: " << x << endl;
  cout << "y: " << y << endl;

  intercambio(x,y);

  cout << "x: " << x << endl;
  cout << "y: " << y << endl;

  intercambio2(&x,&y);

  cout << "x: " << x << endl;
  cout << "y: " << y << endl;

  
  intercambio2(x,y);

  cout << "x: " << x << endl;
  cout << "y: " << y << endl;

  return 0;
}
