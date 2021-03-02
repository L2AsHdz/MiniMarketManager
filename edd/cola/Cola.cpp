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
        cout<<"Cliente "<<cliente.getId()<<" agregado al inicio" <<endl;
    } else {
        this->ultimo->next = nuevo;
        cout<<"Cliente "<<cliente.getId()<<" agregado a la cola"<<endl;
    }
    this->ultimo = nuevo;
}

Cliente Cola::eliminar() {
    Cliente dato;

    if (this->primero == NULL) {
        cout<<"Eliminar: Cola vacia"<<endl;
    } else {
        Node temp = this->primero;
        this->primero = temp->next;
        dato = temp->dato;

        delete temp;
        cout<<"Cliente "<<dato.getId()<<" sacado de la cola"<<endl;
        if (this->primero == NULL) this->ultimo = NULL; 
    }
    return dato;
}

void Cola::mostrarCola() {
    Node actual = this->primero;

    if (this->primero == NULL) {
        cout<<"Mostrar cola: Cola vacia"<<endl;
    } else {
        while (actual != NULL) {
            cout<<actual->dato.getId()<<" ->";
            actual = actual->next;
        }
    }
}