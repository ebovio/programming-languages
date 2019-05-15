/* fichero: Constante-01.C
 *
 * compilar: $ g++ -o Constante-01 Constante-01.C
 * nota: compila con errores
 * propósito: Mostrar como el compilador controla
 */
void
f(const int* p) {
  *p = 10;
}

int
main() {
  int a;
  a = 40;

  f(&a);

  return 0;

}
