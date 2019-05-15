#include <iostream>
using namespace std;
int main()
{
    int c;
    if (cin >> c and c)
    {
        c += 10;
    }
    else
    {
        c = 20;
    }
    cout << c << endl;
    return 0;
}

// El valor de c se inicializa con true o con el valor ingresado por el usuario cuando la entrada es diferente de 0 y después se le suma en 10.
// El valor de c se incializa con 0 o false cuando el valor ingresado es 0 y este cambia entonces a 20.