#include <iostream>
#include "AddClientesController.h"

using namespace std;

AddClientesController::AddClientesController(){}

void AddClientesController::start(Pila* carretas1, Pila* carretas2, 
Cola* clientesEspera, CircularList* clientesCompra, int idCliente, int cantClientes) {
    Cliente cliente;
    int idClienteInicio = idCliente;
    int carreta;
    
    for (idCliente; idCliente < (idClienteInicio + cantClientes); idCliente++) {
        cout<<"El cliente "<<idCliente<<" llega a la tienda."<<endl;
        if (!carretas1->isEmpty() & clientesEspera->isEmpty()) {
            carreta = carretas1->pop();
            cout<<"La carreta "<<carreta<< " es tomada por el cliente "<<idCliente<<"."<<endl;
            clientesCompra->agregar(Cliente(idCliente, carreta));
        } else if (carretas2->isEmpty() & clientesEspera->isEmpty()) {
            carreta = carretas2->pop();
            cout<<"La carreta "<<carreta<< " es tomada por el cliente "<<idCliente<<"."<<endl;
            clientesCompra->agregar(Cliente(idCliente, carretas2->pop()));
        } else {
            clientesEspera->insertar(Cliente(idCliente));
        }
    }
}