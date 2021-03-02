#include <iostream>
#include "Caja.h"

using namespace std;

Caja::Caja(){}

Caja::Caja(int id) {
    this->id = id;
    this->tiempoServicio = 0;
    this->estado = true;
}

int Caja::getId() {
    return this->id;
}

void Caja::aumentarServicio() {
    this->tiempoServicio++;
}

int Caja::getTiempoServicio() {
    return this->tiempoServicio;
}

void Caja::setEstado(bool estado) {
    this->estado = estado;
}

bool Caja::getEstado() {
    return this->estado;
}

void Caja::setCliente(Cliente cliente) {
    this->cliente = cliente;
}

Cliente Caja::getCliente() {
    return this->cliente;
}