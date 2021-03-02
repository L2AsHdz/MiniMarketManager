#include <iostream>
#include "../../view/datosIniciales/DatosIniciales.h"
#include "DatosInicialesController.h"

using namespace std;

DatosInicialesController::DatosInicialesController(){}

void DatosInicialesController::solicitarDatos() {
    bienvenida();
    this->cantClientesEspera = solicitarClientesEnEspera();
    this->cantCarretas1 = solicitarNumeroCarretas(1);
    this->cantCarretas2 = solicitarNumeroCarretas(2);
    this->cantClientesComprando = solicitarClientesComprando();
    this->cantClientesColaPago = solicitarClientesColaPago();
    this->cantCajas = solicitarCantidadCajas();
}

void DatosInicialesController::inicializarEstructuras(Pila* carretas1, Pila* carretas2, Cola* clientesEspera, CircularList* clientesCompra, Cola* clientesPago, LinkedList* cajas) {
    
}