#include <iostream>
#include "Pila.h"

using namespace std;

typedef Nodo* Node;

Pila::Pila(){}

void Pila::push(int id){
    Node inicio = this->pila;
    
    Node nuevo = new Nodo;
    nuevo->dato = id;

    if (inicio->next == NULL) {
        inicio->next = nuevo;
    } else {
        nuevo->next = inicio->next;
        inicio->next = nuevo;
    }
    cout<<"Elemento "<<id<<" agregado a la pila"<<endl;
}

int Pila::pop() {
    int dato = -1;
    Node inicio = this->pila;

    if (inicio->next == NULL) {
        cout<<"Pila vacia, imposible hacer pop"<<endl;
    } else {
        Node auxPop = inicio->next;
        dato = auxPop->dato;

        inicio->next = auxPop->next;
        delete auxPop;
        cout<<"Elemento "<<dato<<" sacado de la pila"<<endl;
    }
    return dato;
}

void Pila::mostrarPila() {
    Node actual = this->pila;

    if (actual->next == NULL) {
        cout<<"Pila vacia, nada por mostrar"<<endl;
    } else {
        while(actual->next != NULL) {
            cout<<actual->next->dato<<" -> ";
            actual = actual->next;
        }
    }
}