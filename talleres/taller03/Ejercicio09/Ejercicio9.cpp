#include <iostream>
using namespace std;
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *pa = &a[0];
    pa += sizeof(a) / sizeof(int) / 2;
    cout << ++pa[-1] << endl;
    return 0;
}

//El programa imprime el valor 6 porque sigue la siguiente secuencia de pasos

//  1. Se asigna un array de tamaño 10 con los valores 1-10 a la variable a.
//  2. Se crea un puntero pa y se le asigna el valor de la dirección en a[0].
//  3. Se obtiene el tamaño del array a y se divide sobre 2.
//  4. Se suma el valor obtenido en "3." al valor actual de pa.
//  5. Incrementa al prefijo de pa en la posición -1
//  6. Imprime el valor