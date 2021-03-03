#include <iostream>
#include <cstdlib>
#include "ClientesEnCajaController.h"

using namespace std;

ClientesEnCajaController::ClientesEnCajaController(){}

void ClientesEnCajaController::start(LinkedList* cajas, Pila* carretas1, Pila* carretas2, int noCajas) {
    int pilaAleatoria;
    Cliente cliente;

    for (int i = 1; i <= noCajas; i++) {
        pilaAleatoria = 1 + rand() % 2;
        Caja* caja = cajas->buscar(i);
        cliente = caja->getCliente();
        
        if (!caja->getEstado()) {
            if (caja->getTiempoAtendido() == caja->getTiempoServicio()) {
                if (pilaAleatoria == 1) {
                    carretas1->push(cliente.getIdCarreta());
                } else {
                    carretas2->push(cliente.getIdCarreta());
                }
                caja->resetTiempoAtendido();
                caja->setEstado(true);
                cout<<"El cliente "<<cliente.getId()<<" salio del sistema y libero la carreta "<<cliente.getIdCarreta()<<"."<<endl;
            } else {
                cout<<"El cliente "<<cliente.getId()<<" esta siendo atendido en la caja "<<caja->getId()<<"."<<endl;
                caja->aumentarTiempoAtendido();
            }
        }
    }
}