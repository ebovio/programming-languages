/*
 * fichero: Referencias-03.cpp
 *
 * compilar: $ g++ -o Referencias-03 Referencias-03.cpp
 *           $ make Referencias-03
 *
 * proposito: Mostrar referencias y direcciones 
 */
#include <iostream>

using namespace std;

int
main() {
  int ui = 0;
  int& rui = ui;

  cout << "ui: "  << ui << endl;
  cout << "rui: " << rui << endl;

  rui++;

  cout << "ui: "  << ui << endl;
  cout << "rui: " << rui << endl;

  int* pp = &rui;

  cout << "&ui: " << &ui << endl;
  cout << "pp:  " << pp << endl;

  (*pp)++;

  cout << "ui: "  << ui << endl;
  cout << "rui: " << rui << endl;
  cout << "pp: "  << *pp << endl;

  return 0;
}
