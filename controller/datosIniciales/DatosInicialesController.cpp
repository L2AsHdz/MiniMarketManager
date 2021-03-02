#include <iostream>
#include "DatosInicialesController.h"

using namespace std;

DatosInicialesController::DatosInicialesController(){
    this->dataView = DatosInicialesView();
}

void DatosInicialesController::solicitarDatos() {
    this->dataView.bienvenida();
    this->cantClientesEspera = this->dataView.solicitarClientesEnEspera();
    this->cantCarretas1 = this->dataView.solicitarNumeroCarretas(1);
    this->cantCarretas2 = this->dataView.solicitarNumeroCarretas(2);
    this->cantClientesComprando = this->dataView.solicitarClientesComprando();
    this->cantClientesColaPago = this->dataView.solicitarClientesColaPago();
    this->cantCajas = this->dataView.solicitarCantidadCajas();
}

void DatosInicialesController::inicializarEstructuras(Pila* carretas1, Pila* carretas2, Cola* clientesEspera, CircularList* clientesCompra, Cola* clientesPago, LinkedList* cajas) {
    
}