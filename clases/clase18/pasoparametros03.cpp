/*
 * fichero: pasoparametros03.cpp
 * compilar: $ g++ -o pasoparametros03 pasoparametros03.cpp
 *           $ make pasoparametros03
 * ejecutar: $ ./pasoparametros03
 */
#include <iostream>

using namespace std;

void intercambio(int &x, int &y);
void imprimirXY(int x, int y);

int
main() {
  int x = 10;
  int y = 20;
  int a = 30;
  int b = 40;
  
  imprimirXY(x,y);
  
  intercambio(x,y);

  imprimirXY(x,y);

  imprimir(a,b);

  intercambio(a,b);

  imprimirXY(a,b);
  
  return 0;
}

inline void
intercambio(int &x, int &y) {
  int tmp = x;
  x = y;
  y = tmp;
}

inline void
imprimirXY(int x, int y) {
  
  cout << "x: " << x << " y: " << y << endl;
}
