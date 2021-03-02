#include <iostream>
#include "CircularList.h"

using namespace std;

typedef Nodo* Node;

CircularList::CircularList(){}

void CircularList::agregar(int dato) {
    Node nuevo = new Nodo;
    nuevo->dato = dato;

    if (this->primero == NULL) {
        this->primero = nuevo;
        cout<<"Elemento "<<dato<<" agregado al inicio"<<endl;
    } else {
        this->ultimo->next = nuevo;
        nuevo->prev = this->ultimo;

        this->primero->prev = nuevo;
        nuevo->next = this->primero;
        cout<<"Elemento "<<dato<<" agregado a la CircleList"<<endl;
    }
    this->ultimo = nuevo;
}

int CircularList::eliminar(int num) {
    return num;
}

void CircularList::mostrarLista() {
    Node actual = this->primero;

    if (actual == NULL) {
        cout<<"No hay nada por mostrar, lista vacia"<<endl;
    } else {
        do {
            cout<<endl<<actual->prev->dato<<"<-"<<actual->dato<<"->"<<actual->next->dato<<endl;
            actual = actual->next;   
        }while (actual != this->primero);
    }
}