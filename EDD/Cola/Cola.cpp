#include <iostream>
#include "Cola.h"

using namespace std;

typedef Nodo* Node;

Cola::Cola(){}

void Cola::insertar(int dato){
    Node inicio = this->primero;
    Node fin = this->ultimo;

    Node nuevo = new Nodo;
    nuevo->dato = dato;

    if (inicio->next == NULL) {
        inicio->next = nuevo;
        fin = nuevo;
    } else {
        fin->next = nuevo;
        fin = nuevo;
    }
}