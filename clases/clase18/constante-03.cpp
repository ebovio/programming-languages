/* fichero: Constante-03.C
 *
 * compilar: $ g++ -o Constante-03 Constante-03.C
 * ejecutar: $ ./Constante-03
 * propósito: 
 */
#include <iostream>

using namespace std;

const int c1 = 10;
const int* pc1 = &c1;

int
main() {
  cout << c1 << endl;
  cout << *pc1 << endl;

  return 0;
}
