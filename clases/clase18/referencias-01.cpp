/*
 * fichero: Referencias-01.cpp
 *
 * compilar: $ g++ -o Referencias-01 Referencias-01.cpp
 *           $ make Referencias-01
 *
 * ejecutar: $ ./Referencias-01
 * proposito: Mostrar el uso de las referencias
 */
#include <iostream>

using namespace std;

int
main() {
  int i = 1;
  int& r = i;
  int x = r;

  cout << "Valor de i: " << i << endl;
  cout << "Valor de r: " << r << endl;
  cout << "Valor de x: " << x << endl;

  r = 10; 

  
  cout << "Valor de i: " << i << endl;
  cout << "Valor de r: " << r << endl;
  cout << "Valor de x: " << x << endl;

  return 0;
}
