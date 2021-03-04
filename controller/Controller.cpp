#include <iostream>
#include "Controller.h"

using namespace std;

Controller::Controller(){
    this->inicialData = DatosInicialesController();
    this->addCliente = AddClientesController();
    this->colaEspera = ColaEsperaController();
    this->areaCompras = AreaComprasController();
    this->colaPago = ColaPagoController();
    this->clientesEnCaja = ClientesEnCajaController();
    this->fileManager = FileGenerator();

    this->pilaCarretas1 = Pila();
    this->pilaCarretas2 = Pila();
    this->clientesEnEspera = Cola();
    this->clientesComprando = CircularList();
    this->clientesEsperaPago = Cola();
    this->cajas = LinkedList();
}

void Controller::iniciar() {
    this->inicialData.solicitarDatos();

    cout<<endl<<"Inicializando estructuras de datos"<<endl;
    this->inicialData.inicializarEstructuras(&this->pilaCarretas1, &this->pilaCarretas2, &this->clientesEnEspera,
    &this->clientesComprando, &this->clientesEsperaPago, &this->cajas);
    this->lastIdCliente = this->inicialData.getLastIdCliente();

    ejecutarPasoSiguiente();
}

void Controller::ejecutarPasoSiguiente() {
    char option;
    int i = 0;
    
    do {
        cout<<endl<<"Desea ejecutar el siguiente paso? (y/n) ";
        cin>>option;

        if (option == 'y') {
            cout<<endl<<"\n\n*************************PASO "<<i<<"*************************"<<endl;
            agregarClientesNuevos();
            verificarColaEspera();
            verificarAreaCompras();
            verificarColaPago();
            salidaSistema();
            cout<<"Se ha generado el archivo"<<endl;
            this->fileManager.generar(&this->pilaCarretas1, &this->pilaCarretas2, &this->clientesEnEspera, &this->clientesComprando, &this->clientesEsperaPago, &this->cajas);
        }
        i++;
    } while (option != 'n');
}

void Controller::agregarClientesNuevos() {
    int cantClientes;
    int idCliente;
    cout<<endl<<"Cuantos clientes entraran al sistema ";
    cin>>cantClientes;
    idCliente = this->addCliente.start(&this->pilaCarretas1, &this->pilaCarretas2, &this->clientesEnEspera, 
    &this->clientesComprando, this->lastIdCliente, cantClientes);
    this->lastIdCliente = idCliente;
    cout<<endl<<this->lastIdCliente<<" - "<<idCliente<<endl;
}

void Controller::verificarColaEspera() {
    cout<<endl<<"Verificando cola de espera"<<endl;
    this->colaEspera.start(&this->clientesEnEspera, &this->pilaCarretas1, &this->pilaCarretas2, &this->clientesComprando);
}

void Controller::verificarAreaCompras() {
    cout<<endl<<"Verificando area de compras."<<endl;
    this->areaCompras.start(&this->clientesComprando, &this->clientesEsperaPago, &this->cajas);
}

void Controller::verificarColaPago() {
    cout<<endl<<"Verificando cola de pago."<<endl;
    this->colaPago.start(&this->clientesEsperaPago, &this->cajas);
}

void Controller::salidaSistema() {
    cout<<endl<<"Atendiendo clientes en caja"<<endl;
    this->clientesEnCaja.start(&this->cajas, &this->pilaCarretas1, &this->pilaCarretas2, this->inicialData.getCantCajas());
}