#include <string>
#include <iostream>
#include <ctype.h>
#include <stdio.h>

using namespace std;

int main()
{
    char expression[] = "BBnNmmmMjKlKkkk";
    int pares = strlen(expression) / 2;
    int buenas = 0;
    int malas = 0;

    cout << "El siguiente programa le ayuda a detectar la posición en la que hay errores, iniciando en la posición 0" << endl;
    cout << "La expressión a evaluar es: " << expression << endl;

    int inicio = 0;

    
    if (!isupper(expression[0])) {
        inicio = 1;
    }
    
    for (int i = inicio; i < strlen(expression); i += 2)
    {
        if ((isupper(expression[i]) && isupper(expression[i + 1])) || (!isupper(expression[i]) && !isupper(expression[i + 1])))
        {
            malas++;
            cout << "Error en la posición: " << i << endl;
        }
        else
        {
            buenas++;
        }
    }

    cout << pares << endl;
    cout << buenas << endl;
    cout << malas << endl;

    return 0;
}