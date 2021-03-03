#include <iostream>
#include <cstdlib>
#include "AreaComprasController.h"

using namespace std;

AreaComprasController::AreaComprasController(){}

void AreaComprasController::start(CircularList* clientesComprando, Cola* clientesColaPago, LinkedList* cajas) {
    int idAleatorio = 1 + rand() % 100;
    int idCaja;
    Cliente cliente;

    if (!clientesComprando->isEmpty()) {
        cliente = clientesComprando->eliminar(idAleatorio);
        if (cliente.getId() == idAleatorio) {
            idCaja = cajas->isFree();
            if ((idCaja != -1) & clientesColaPago->isEmpty()) {
                Caja* caja = cajas->buscar(idCaja);
                caja->setCliente(cliente);
                caja->setEstado(false);
                cout<<"El cliente "<<cliente.getId()<<" ha pasado a la caja "<<idCaja<<"."<<endl;
            } else {
                clientesColaPago->insertar(cliente);
                cout<<"El cliente "<<cliente.getId()<<" ha ingresado a la cola de pago."<<endl;
            }
        }
    }    
}