#include <iostream>
#include "CircularList.h"

using namespace std;

typedef Nodo* Node;

CircularList::CircularList(){}

void CircularList::agregar(int dato) {
    Node nuevo = new Nodo;
    Node actual = this->inicio;
    nuevo->dato = dato;

    if (this->inicio == NULL) {
        this->inicio = nuevo;
        cout<<"Elemento "<<dato<<" agregado al inicio"<<endl;
    } else {

        while (actual->next != this->inicio) {
            actual = actual->next;
        }
    }
    actual->next = nuevo;
    nuevo->prev = actual;
    this->inicio->prev = nuevo;
}

int CircularList::eliminar(int num) {
    return num;
}

void CircularList::mostrarLista() {
    Node actual = this->inicio;

    do {
        cout<<endl<<actual->prev->dato<<"<-"<<actual->dato<<"->"<<actual->next->dato<<endl;
        actual = actual->next;
    }while (actual != this->inicio);
}