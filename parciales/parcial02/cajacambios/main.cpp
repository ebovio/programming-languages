#include "cambios.h"
#include "automatizador.h"
#include "helper.h"
#include <string>
#include <iostream>

using namespace std;

void
hacerOperacion(AutomatizadorCambios& automatizador, string operacion);

int
main(void) {
  const int nCajas = 3 ;

  CajaDeCambios cajas[nCajas];
  AutomatizadorCambios automatizador[nCajas] = { AutomatizadorCambios(cajas[0]),
						 AutomatizadorCambios(cajas[1]),
						 AutomatizadorCambios(cajas[2])
  };

  int i;
  string operacion;
  while (cin >> i >> operacion) {
    hacerOperacion(automatizador[i], operacion);
    string estado;
    //traducirEstadoCambioACadena(automatizador[i].obtenerCambio(), estado);
    cout << "Caja: " << i << " " << estado << endl;
  }
}

void
hacerOperacion(AutomatizadorCambios& automatizador, string operacion) {
  if (operacion == "subir") {
    automatizador.subir();
  }
  else if (operacion == "bajar") {
    automatizador.bajar();
  }
  else if (operacion == "neutralizar") {
    automatizador.neutralizar();
  }
  else if (operacion == "reversar") {
    automatizador.reversar();
  }
}
