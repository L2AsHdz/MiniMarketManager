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
    int tiempoServicio;

    //Se agregan los clientes a la cola de pago
    cout<<endl<<"********************Cola de pago********************"<<endl;
    for(idCliente; idCliente <= this->cantClientesColaPago; idCliente++) {
        clientesPago->insertar(Cliente(idCliente, idCarreta));
        cout<<"El cliente "<<idCliente<<" ha ingresado a la cola de pago."<<endl;
        idCarreta++;
    }
    clienteActual = idCliente;
    carretaActual = idCarreta;

    //Se agregan los clientes al area de compras
    cout<<endl<<"********************Area de compras********************"<<endl;
    for (idCliente; idCliente < (clienteActual + this->cantClientesComprando); idCliente++) {
        clientesCompra->agregar(Cliente(idCliente, idCarreta));
        idCarreta++;
    }
    clienteActual = idCliente;
    carretaActual = idCarreta;
    
    //Se agregan las carretas a la pila 1
    cout<<endl<<"********************Pila carretas 1********************"<<endl;
    for (idCarreta; idCarreta < (carretaActual + this->cantCarretas1); idCarreta++) {
        carretas1->push(idCarreta);
        cout<<"La carreta "<<idCarreta<<" se ha agregado a la pila 1."<<endl;
    }
    carretaActual = idCarreta;

    //Se agregan las carretas a la pila 2
    cout<<endl<<"********************Pila carretas 2********************"<<endl;
    for (idCarreta; idCarreta < (carretaActual + this->cantCarretas2); idCarreta++) {
        carretas2->push(idCarreta);
        cout<<"La carreta "<<idCarreta<<" se ha agregado a la pila 2."<<endl;
    }

    //Se agregan los clientes a la cola de espera
    cout<<endl<<"********************Cola de espera********************"<<endl;
    for (idCliente; idCliente < (clienteActual + this->cantClientesEspera); idCliente++) {
        clientesEspera->insertar(Cliente(idCliente));
        cout<<"El cliente "<<idCliente<<" ha ingresado a la cola de espera."<<endl;
    }

    //Se agregan las caja a la lista
    cout<<endl<<"********************Cajas********************"<<endl;
    for (int i = 1; i <= cantCajas; i++) {
        cout<<"Ingrese el tiempo de servicio para la caja "<<i<<": ";
        cin>>tiempoServicio;
        cajas->agregar(Caja(i, tiempoServicio));cout<<endl;
    }
}