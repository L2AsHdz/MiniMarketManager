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
}

int Pila::pop() {
    int dato = -1;

    if (this->pila == NULL) {
        cout<<"No hay carretas en la pila"<<endl;
    } else {
        Node auxPop = this->pila;
        this->pila = auxPop->next;
        dato = auxPop->dato;
        delete auxPop;
    }
    return dato;
}

void Pila::mostrarPila() {
    Node actual = this->pila;

    if (actual == NULL) {
        cout<<"No hay carretas en la pila"<<endl;
    } else {
        while(actual != NULL) {
            cout<<actual->dato<<" -> ";
            actual = actual->next;
        }
    }
}

bool Pila::isEmpty() {
    if (this->pila == NULL) {
        return true;
    } else {
        return false;
    }
}

string Pila::getNodos() {
    string nodos ="";
    Node actual = this->pila;

    while(actual != NULL) {
        nodos = nodos + "|" + to_string(actual->dato);
        actual = actual->next;
    }

    return nodos;
}