#include <iostream>
using namespace std;
int main(void)
{
    int a = 10;
    bool b = true;
    char c = 'c';
    double d = 10.20;
    cout << a;
    cout << b;
    cout << c;
    cout << d;

    return 0;
}

//El programa anterior imprime "101c10.2"

// Esto se debe a que imprime los valores de las variables en una sola línea y sin espacios.
    // Esto sucede porque el cout manda todo lo siguiente al "<<" a la línea de salida
    // y no agrega saltos de línea al final.
    //Entonces, 101c10.2 = abcd, donde 
        // a = 10
        // b = 1 (representación boleana de true)
        // c = 'c'
        // d = 10.20