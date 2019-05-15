#include "cambios.h"

CajaDeCambios::CajaDeCambios() : estado(Neutra), embrague(Libre) {}

void CajaDeCambios::establecerEmb()
{
    this->embrague = Montado;
}
void CajaDeCambios::liberarEmb()
{
    this->embrague = Libre;
}
void CajaDeCambios::ponerPrimera()
{
    this->estado = Primera;
}
void CajaDeCambios::ponerSegunda()
{
    this->estado = Segunda;
}
void CajaDeCambios::ponerTercera()
{
    this->estado = Tercera;
}
void CajaDeCambios::ponerCuarta()
{
    this->estado = Cuarta;
}
void CajaDeCambios::ponerQuinta()
{
    this->estado = Quinta;
}
void CajaDeCambios::ponerReversa()
{
    this->estado = Reversa;
}
void CajaDeCambios::ponerNeutra()
{
    this->estado = Neutra;
}
const EstadoCambio CajaDeCambios::obtenerCambio()
{
    return this->estado;
}
