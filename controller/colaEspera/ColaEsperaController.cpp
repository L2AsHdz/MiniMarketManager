#include <iostream>
#include "ColaEsperaController.h"

using namespace std;

ColaEsperaController::ColaEsperaController(){}

void ColaEsperaController::start(Cola* clientesEspera, Pila* carretas1, 
Pila* carretas2, CircularList* clientesComprando) {
    
    while (!clientesEspera->isEmpty() & !carretas1->isEmpty()) {
        agregarClienteACompras(clientesComprando, clientesEspera->eliminar().getId(), carretas1->pop());
    }

    while (!clientesEspera->isEmpty() & !carretas2->isEmpty()) {
        agregarClienteACompras(clientesComprando, clientesEspera->eliminar().getId(), carretas2->pop());
    }

    
}

void ColaEsperaController::agregarClienteACompras(CircularList* clientesCompra, int id, int carreta) {
    cout<<"La carreta "<<carreta<< " es tomada por el cliente "<<id<<"."<<endl;
    clientesCompra->agregar(Cliente(id, carreta));
}