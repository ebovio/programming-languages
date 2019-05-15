#pragma once

class Padre {

 public:
  Padre(int);
  ~Padre();
  void estValor(int);
  int obtValor() const;
  int sumarAlValor(int) const;
 private:
  int valor1;
};

class Hijo : public Padre {
 public:
  Hijo(int,int);
  ~Hijo();
  void estValor(int);
  int obtValor() const;
  int sumarAlValor(int) const;
 private:
  int valor2; 
};


