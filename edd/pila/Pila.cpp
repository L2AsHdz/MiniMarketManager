#include <iostream>
#include "Pila.h"

using namespace std;

typedef Nodo<int>* Node;

Pila::Pila(){
    this->pila = NULL;
}

void Pila::push(int id){
    
    Node nuevo = new Nodo<int>;
    nuevo->dato = id;

    nuevo->next = this->pila;
    this->pila = nuevo;
    cout<<"Carreta "<<id<<" agregada a la pila"<<endl;
}

int Pila::pop() {
    int dato = -1;

    if (this->pila == NULL) {
        cout<<"Pila vacia, imposible hacer pop"<<endl;
    } else {
        Node auxPop = this->pila;
        this->pila = auxPop->next;
        dato = auxPop->dato;
        delete auxPop;
        cout<<"Carreta "<<dato<<" sacada de la pila"<<endl;
    }
    return dato;
}

void Pila::mostrarPila() {
    Node actual = this->pila;

    if (actual == NULL) {
        cout<<"Pila vacia, nada por mostrar"<<endl;
    } else {
        while(actual != NULL) {
            cout<<actual->dato<<" -> ";
            actual = actual->next;
        }
    }
}