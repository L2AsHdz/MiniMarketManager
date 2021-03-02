#include <iostream>
#include "Controller.h"

using namespace std;

Controller::Controller(){
    this->inicialData = DatosInicialesController();

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
}