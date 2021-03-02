#include <iostream>
#include "Cliente.h"

using namespace std;

Cliente::Cliente(){}

Cliente::Cliente(int id) {
    this->id = id;
}

Cliente::Cliente(int id, int idCarreta) {
    this->id = id;
    this->idCarreta = idCarreta;
}

void Cliente::setId(int id) {
    this->id = id;
}

int Cliente::getId() {
    return this->id;
}

void Cliente::setIdCarreta(int idCarreta) {
    this->idCarreta = idCarreta;
}

int Cliente::getIdCarreta() {
    return this->idCarreta;
}