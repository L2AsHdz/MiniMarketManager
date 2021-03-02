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
    int idCarreta = 1;
    int idCliente = 1;
    int clienteActual;
    int carretaActual;

    for(idCliente; idCliente <= this->cantClientesColaPago; idCliente++) {
        clientesPago->insertar(Cliente(idCliente, idCarreta));
        idCarreta++;
    }
    clienteActual = idCliente;
    carretaActual = idCarreta;

    for (idCliente; idCliente < (clienteActual + this->cantClientesComprando); idCliente++) {
        clientesCompra->agregar(Cliente(idCliente, idCarreta));
        idCarreta++;
    }
    clienteActual = idCliente;
    carretaActual = idCarreta;
    
    for (idCarreta; idCarreta < (carretaActual + this->cantCarretas1); idCarreta++) {
        carretas1->push(idCarreta);
    }
    carretaActual = idCarreta;

    for (idCarreta; idCarreta < (carretaActual + this->cantCarretas2); idCarreta++) {
        carretas2->push(idCarreta);
    }

    for (idCliente; idCliente < (clienteActual + this->cantClientesEspera); idCliente++) {
        clientesEspera->insertar(Cliente(idCliente));
    }

    for (int i = 1; i <= cantCajas; i++) {
        cajas->agregar(Caja(i));
    }
}