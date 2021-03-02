#include <iostream>
#include "../../view/datosIniciales/DatosIniciales.h"

using namespace std;

int cantClientesEspera;
int cantCarretas1;
int cantCarretas2;
int cantClientesComprando;
int cantClientesColaPago;
int cantCajas;

void solicitarDatos() {
    bienvenida();
    cantClientesEspera = solicitarClientesEnEspera();
    cantCarretas1 = solicitarNumeroCarretas(1);
    cantCarretas2 = solicitarNumeroCarretas(2);
    cantClientesComprando = solicitarClientesComprando();
    cantClientesColaPago = solicitarClientesColaPago();
    cantCajas = solicitarCantidadCajas();
}

void inicializarEstructuras() {
    
}