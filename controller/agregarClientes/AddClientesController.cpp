#include <iostream>
#include "AddClientesController.h"

using namespace std;

AddClientesController::AddClientesController(){}

int AddClientesController::start(Pila* carretas1, Pila* carretas2, 
Cola* clientesEspera, CircularList* clientesCompra, int idCliente, int cantClientes) {
    int idClienteInicio = idCliente;
    
    for (idCliente; idCliente < (idClienteInicio + cantClientes); idCliente++) {
        cout<<"El cliente "<<idCliente<<" llega a la tienda."<<endl;
        if (!carretas1->isEmpty() & clientesEspera->isEmpty()) {
            agregarClienteACompras(clientesCompra, idCliente, carretas1->pop());
        } else if (!carretas2->isEmpty() & clientesEspera->isEmpty()) {
            agregarClienteACompras(clientesCompra, idCliente, carretas2->pop());
        } else {
            clientesEspera->insertar(Cliente(idCliente));
            cout<<"El cliente "<<idCliente<<" ha ingresado a la cola de espera."<<endl;
        }
    }
    return idCliente;
}

void AddClientesController::agregarClienteACompras(CircularList* clientesCompra, int id, int carreta) {
    cout<<"La carreta "<<carreta<< " es tomada por el cliente "<<id<<"."<<endl;
    clientesCompra->agregar(Cliente(id, carreta));
}