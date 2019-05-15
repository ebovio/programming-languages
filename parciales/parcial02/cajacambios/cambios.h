#pragma once

enum EstadoCambio
{
    Neutra,
    Primera,
    Segunda,
    Tercera,
    Cuarta,
    Quinta,
    Reversa
};

enum Embrague
{
    Libre,
    Montado
};

class CajaDeCambios
{
  public:
    CajaDeCambios();
    void establecerEmb();
    void liberarEmb();
    void ponerPrimera();
    void ponerSegunda();
    void ponerTercera();
    void ponerCuarta();
    void ponerQuinta();
    void ponerReversa();
    void ponerNeutra();
    EstadoCambio obtenerCambio() const;

  private:
    EstadoCambio estado;
    Embrague embrague;
};
