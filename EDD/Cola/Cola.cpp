#include <iostream>
#include "Cola.h"

using namespace std;

typedef Nodo* Node;

Cola::Cola(){}

void Cola::insertar(int dato) {
    Node nuevo = new Nodo;
    nuevo->dato = dato;

    if(this->primero == NULL) {
        this->primero = nuevo;
        cout<<"Elemento "<<dato<<" agregado al inicio" <<endl;
    } else {
        this->ultimo->next = nuevo;
        cout<<"Elemento "<<dato<<" agregado a la cola"<<endl;
    }
    this->ultimo = nuevo;
}

int Cola::eliminar() {
    int dato = -1;

    if (this->primero == NULL) {
        cout<<"Eliminar: Cola vacia"<<endl;
    } else {
        Node temp = this->primero;
        this->primero = temp->next;
        dato = temp->dato;

        delete temp;
        cout<<"Elemento "<<dato<<" sacado de la cola"<<endl;
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
            cout<<actual->dato<<" ->";
            actual = actual->next;
        }
    }
}