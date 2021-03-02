#include <iostream>
#include "Cola.h"

using namespace std;

typedef Nodo<Cliente>* Node;

Cola::Cola(){}

void Cola::insertar(Cliente cliente) {
    Node nuevo = new Nodo<Cliente>;
    nuevo->dato = cliente;

    if(this->primero == NULL) {
        this->primero = nuevo;
    } else {
        this->ultimo->next = nuevo;
    }
    this->ultimo = nuevo;
}

Cliente Cola::eliminar() {
    Cliente dato;

    if (this->primero == NULL) {
        cout<<"No hay clientes en la cola"<<endl;
    } else {
        Node temp = this->primero;
        this->primero = temp->next;
        dato = temp->dato;

        delete temp;
        if (this->primero == NULL) this->ultimo = NULL; 
    }
    return dato;
}

void Cola::mostrarCola() {
    Node actual = this->primero;

    if (this->primero == NULL) {
        cout<<"No hay clientes en la cola"<<endl;
    } else {
        while (actual != NULL) {
            cout<<actual->dato.getId()<<" ->";
            actual = actual->next;
        }
    }
}