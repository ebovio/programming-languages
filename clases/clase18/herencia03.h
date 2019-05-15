#pragma once

class Padre {

 public:
  Padre(int);
  virtual ~Padre();
  virtual void estValor(int);
  virtual int obtValor() const;
  virtual int sumarAlValor(int) const;
 private:
  int valor1;
};

class Hijo : public Padre {
 public:
  Hijo(int,int);
  ~Hijo();
  virtual void estValor(int);
  virtual int obtValor() const;
  virtual int sumarAlValor(int) const;
 private:
  int valor2; 
};


