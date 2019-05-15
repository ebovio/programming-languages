#include "helper.h"

void traducirEstadoCambioACadena(const EstadoCambio estado, string& string){
  switch (EstadoCambio){
  case Neutra :
    string = "Neutra";
    break;
  case Primera :
    string = "Primera";
    break;
  case Segunda :
    string = "Segunda";
    break;
  case Tercera :
    string = "Tercera";
    break;
  case Cuarta :
    string = "Cuarta";
    break;
  case Quinta :
    string = "Quinta";
    break;
  case Reversa :
    string = "Reversa";
    break;
  default:
    break;
  }
}
