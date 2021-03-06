#include <iostream>
#include "Caja.h"

using namespace std;

Caja::Caja(){}

Caja::Caja(int id, int tiempoServicio) {
    this->id = id;
    this->tiempoServicio = tiempoServicio;
    this->tiempoAtendido = 0;
    this->estado = true;
}

int Caja::getId() {
    return this->id;
}

void Caja::setServicio(int tiempoServicio) {
    this->tiempoServicio = tiempoServicio;
}

int Caja::getTiempoServicio() {
    return this->tiempoServicio;
}

void Caja::aumentarTiempoAtendido() {
    this->tiempoAtendido++;
}

void Caja::resetTiempoAtendido() {
    this->tiempoAtendido = 0;
}

int Caja::getTiempoAtendido() {
    return this->tiempoAtendido;
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