/* fichero: Constante-05.C
 *
 * compilar: $ g++ -o Constante-05 Constante-05.C
 * nota: No ejecuta
 * propósito: Mostrar que las constantes de punteros de T pueden
 *            apuntar valores de T* y const T*, pero no de otro tipo
 */
#include <iostream>

using namespace std;

int
main() {
   int valor = 1;
   const int valorConst = 2;
   const int* cip1 = &valorConst; // Ok
   const int* cip2 = &valor;      // Ok
   int* ip = &valorConst;         // Error
   *ip = 7;                       // Error
}
