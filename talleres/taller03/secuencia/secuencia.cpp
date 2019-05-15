#include <iostream>
#include <limits>
using namespace std;

int main()
{
	float valor, promedio, promAnterior, promMayor, factor, suma, cont;

	cout << "ingrese el factor de crecimiento :" << endl;
	cin >> factor;

	suma = 0;
	promedio = 0;
	promAnterior = 0;
	promMayor = 0;

	while (true)
	{

		cout << "ingrese un valor:" << endl;
		cin >> valor;
		suma = suma + valor;
		cont = cont + 1;
		promedio = suma / cont;

		if (valor > promAnterior)
		{
			promedio = promedio + valor / factor;
			promAnterior = promedio;

			if (promedio > promMayor)
			{
				promMayor = promedio;
			}
		}

		if (valor <= promMayor)
		{
			promedio = promedio + valor * factor;
			promAnterior = promedio;

			if (promedio > promMayor)
			{
				promMayor = promedio;
			}
		}

		cout << "el promedio es : " << promedio << endl;
	}
}
