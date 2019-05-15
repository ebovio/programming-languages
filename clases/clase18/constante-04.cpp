/* fichero: Constante-04.C
 *
 * compilar: $ g++ -o Constante-04 Constante-04.C
 * ejecutar: $ ./Constante-04
 * propósito: 
 */
#include <iostream>

using namespace std;


int
main() {
  const int c1 = 10;
  const int* pc1 = &c1;

  cout << c1 << endl;
  cout << *pc1 << endl;

  return 0;
}
