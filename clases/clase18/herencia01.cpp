#include "herencia01.h"

Padre::Padre(int valor1) : valor1(valor1) { }

Padre::~Padre() { }

void Padre::estValor(int valor1) {
  this->valor1 = valor1;
}

int Padre::obtValor() const {
  return valor1;
}

int Padre::sumarAlValor(int valor) const {
  return valor1 + valor;
}

Hijo::Hijo(int valor1, int valor2) :
  Padre(valor1), valor2(valor2) { }

Hijo::~Hijo() { }

void Hijo::estValor(int valor2) {
  this->valor2 = valor2;
}

int Hijo::obtValor() const {
  return valor2;
}

int Hijo::sumarAlValor(int valor) const {
  
  return Padre::obtValor() + valor2 + valor;
}
