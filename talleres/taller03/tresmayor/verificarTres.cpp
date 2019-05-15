#include <iostream>
#include "tresMayor.cpp"
using namespace std;

int main()
{
    int a, b, c;
    for (int i = 0; i < 4; i++)
    {
        cout << "Valor a: ";
        cin >> a;
        cout << "Valor b: ";
        cin >> b;
        cout << "Valor c: ";
        cin >> c;

        int mayor = tresMayor(a, b, c);

        cout << "El mayor es: " << mayor << endl;
    }

    return 0;
}
