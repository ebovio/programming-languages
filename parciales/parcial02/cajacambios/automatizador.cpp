#include "automatizador.h"

AutomatizadorCambios::AutomatizadorCambios(CajaDeCambios caja) : caja(caja)
{
}
void AutomatizadorCambios::neutralizar()
{
    AutomatizadorCambios::caja.ponerNeutra();
}
void AutomatizadorCambios::reversar()
{
    AutomatizadorCambios::caja.ponerReversa();
}
void AutomatizadorCambios::subir()
{

    if (AutomatizadorCambios::caja.obtenerCambio()==Neutra) {
        AutomatizadorCambios::caja.ponerPrimera();
    }else if(AutomatizadorCambios::caja.obtenerCambio()==Primera){
       AutomatizadorCambios::caja.ponerSegunda();
    }else if(AutomatizadorCambios::caja.obtenerCambio()==Segunda){
       AutomatizadorCambios::caja.ponerTercera();
    }else if(AutomatizadorCambios::caja.obtenerCambio()==Tercera){
       AutomatizadorCambios::caja.ponerCuarta();
    }else if(AutomatizadorCambios::caja.obtenerCambio()==Cuarta){
       AutomatizadorCambios::caja.ponerQuinta();
    }

}
void AutomatizadorCambios::bajar()
{
    if (AutomatizadorCambios::caja.obtenerCambio()==Reversa) {
        AutomatizadorCambios::caja.ponerNeutra();
    }else if(AutomatizadorCambios::caja.obtenerCambio()==Primera){
       AutomatizadorCambios::caja.ponerNeutra();
    }else if(AutomatizadorCambios::caja.obtenerCambio()==Segunda){
       AutomatizadorCambios::caja.ponerPrimera();
    }else if(AutomatizadorCambios::caja.obtenerCambio()==Tercera){
       AutomatizadorCambios::caja.ponerSegunda();
    }else if(AutomatizadorCambios::caja.obtenerCambio()==Cuarta){
       AutomatizadorCambios::caja.ponerTercera();
    }else if(AutomatizadorCambios::caja.obtenerCambio()==Quinta){
       AutomatizadorCambios::caja.ponerCuarta();
    }
}
EstadoCambio AutomatizadorCambios::obtenerCambio()
{
    return AutomatizadorCambios::caja.obtenerCambio();
}
