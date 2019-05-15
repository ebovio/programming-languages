#include "herencia03.h"
#include <iostream>
#include <string>

using namespace std;

void mostrarValor(string*, Padre*);
void mostrarValor(string*, Hijo*);
void sumarValor(string*, Padre*, int);
void sumarValor(string*, Hijo*, int);

int
main(void) {

  Padre unPadre(1);
  Hijo unHijo(2,3);
  string msgPadre("Padre: ");
  string msgHijo("Hijo: ");
  Padre *pUnPadre;
  string *pMsg;

  pUnPadre = &unPadre;
  pMsg = &msgPadre;

  mostrarValor(pMsg, pUnPadre);

  pUnPadre = &unHijo;
  pMsg = &msgHijo;
  
  mostrarValor(pMsg, pUnPadre);

  pUnPadre = &unPadre;
  pMsg = &msgPadre;
  
  sumarValor(pMsg, pUnPadre, 1);

  pUnPadre = &unHijo;
  pMsg = &msgHijo;
  
  sumarValor(pMsg, pUnPadre, 1);

  Hijo otroHijo(2,3);
  Hijo* pHijo;

  pHijo = &otroHijo;
  pMsg = &msgHijo;

  mostrarValor(pMsg, pHijo);
  sumarValor(pMsg, pHijo, 1);

  return 0;
}

void mostrarValor(string* msg, Padre* padre) {

  cout << *msg
       << " valor: "
       << padre->obtValor()
       << endl;
}

void mostrarValor(string* msg, Hijo* hijo) {

  cout << *msg
       << " valor: "
       << hijo->obtValor()
       << endl;
}

void sumarValor(string* msg, Padre* padre, int operador) {

  padre->estValor(padre->sumarAlValor(operador));
  mostrarValor(msg, padre);
}

void sumarValor(string* msg, Hijo* hijo, int operador) {

  hijo->estValor(hijo->sumarAlValor(operador));
  mostrarValor(msg, hijo);
}
