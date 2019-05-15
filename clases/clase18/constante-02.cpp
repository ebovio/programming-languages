/* fichero: Constante-02.C
 *
 * compilar: $ g++ -o Constante-02 Constante-02.C
 * ejecutar: $ ./Constante-02
 * propósito: Mostrar como el compilador controla
 */
#include <iostream>

using namespace std;

void
f(const int* p) {
  cout << *p << endl;
}

int
main() {
  int a;
  a = 40;

  f(&a);

  return 0;

}
