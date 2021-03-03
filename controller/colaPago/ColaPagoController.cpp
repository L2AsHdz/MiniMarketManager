#include <iostream>
#include "ColaPagoController.h"

using namespace std;

ColaPagoController::ColaPagoController(){}

void ColaPagoController::start(Cola* colaPago, LinkedList* cajas) {
    int idCajaLibre;
    Cliente cliente;

    while (!colaPago->isEmpty() & (idCajaLibre != -1)) {
        idCajaLibre = cajas->isFree();
        cliente = colaPago->eliminar();
        Caja* caja = cajas->buscar(idCajaLibre);
        caja->setCliente(cliente);
        caja->setEstado(false);
        cout<<"El cliente "<<cliente.getId()<<" ha pasado a la caja "<<idCajaLibre<<"."<<endl;
    }
}