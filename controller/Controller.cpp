#include <iostream>
#include "Controller.h"

//Controlador para datos iniciales


/*//Pilas para las carretas
Pila pilaCarretas1 = Pila();
Pila pilaCarretas2 = Pila();

//Cola de espera de clientes
Cola clientesEnEspera = Cola();

//Lista circular para clientes comprando
CircularList clientesComprando = CircularList();

//Cola de espera para pagar
Cola clientesEsperaPago = Cola();

//LinkedList para las cajas
LinkedList cajas = LinkedList();*/

Controller::Controller(){
    this->inicialData = DatosInicialesController();
}

void Controller::iniciar() {
    this->inicialData.solicitarDatos();
    //inicialDatainicializarEstructuras();
}