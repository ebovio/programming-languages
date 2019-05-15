/*
 * fichero: pasoparametros02.cpp
 * compilar: $ g++ -o pasoparametros02 pasoparametros02.cpp
 *           $ make pasoparametros02
 * ejecutar: $ ./pasoparametros02
 */
#include <iostream>

using namespace std;

void intercambio(int *x, int *y);
void imprimirXY(int x, int y);

int
main() {
  int x = 10;
  int y = 20;
  
  imprimirXY(x,y);
  
  intercambio(&x,&y);

  imprimirXY(x,y);
  
  return 0;
}

inline void
intercambio(int *x, int *y) {
  int tmp = *x;
  *x = *y;
  *y = tmp;
}

inline void
imprimirXY(int x, int y) {
  
  cout << "x: " << x << " y: " << y << endl;
}
