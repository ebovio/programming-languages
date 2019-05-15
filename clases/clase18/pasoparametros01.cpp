/*
 * fichero: pasoparametros01.cpp
 * compilar: $ g++ -o pasoparametros01 pasoparametros01.cpp
 *           $ make pasoparametros01
 * ejecutar: $ ./pasoparametros01
 */
#include <iostream>

using namespace std;

void intercambio(int x, int y);   // declarar una función
void imprimirXY(int x, int y);

int
main() {
  int x = 10;
  int y = 20;
  
  imprimirXY(x,y);
  
  intercambio(x,y);

  imprimirXY(x,y);
  
  return 0;
}

// definición de una función
void
intercambio(int x, int y) {
  int tmp = x;
  x = y;
  y = tmp;
}

void
imprimirXY(int x, int y) {
  
  cout << "x: " << x << " y: " << y << endl;
}
