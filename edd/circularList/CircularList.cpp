#include <iostream>
#include "CircularList.h"

using namespace std;

typedef Nodo<Cliente>* Node;

CircularList::CircularList(){}

void CircularList::agregar(Cliente cliente) {
    Node nuevo = new Nodo<Cliente>;
    nuevo->dato = cliente;

    if (this->primero == NULL) {
        nuevo->next = nuevo;
        nuevo->prev = nuevo;
        this->primero = nuevo;
        cout<<"Cliente "<<cliente.getId()<<" agregado al inicio"<<endl;
    } else {
        this->ultimo->next = nuevo;
        nuevo->prev = this->ultimo;

        this->primero->prev = nuevo;
        nuevo->next = this->primero;
        cout<<"Cliente "<<cliente.getId()<<" agregado a la CircleList"<<endl;
    }
    this->ultimo = nuevo;
}

Cliente CircularList::eliminar(int num) {
    Cliente dato;

    if (this->primero == NULL) {
        cout<<"Lista vacia, nada por eliminar"<<endl;
        return dato;
    } else {
        Node actual = this->primero;

        do {
            if (actual->dato.getId() == num) {

                if (actual == this->primero) {
                    this->primero = this->primero->next;
                    this->primero->prev = ultimo;
                    this->ultimo->next = this->primero;
                } else if (actual == this->ultimo) {
                    this->ultimo = ultimo->prev;
                    this->primero->prev = ultimo;
                    this->ultimo->next = this->primero;
                } else {
                    actual->prev->next = actual->next;
                    actual->next->prev = actual->prev;
                }

                if (actual == actual->next) this->primero = NULL; 
                dato = actual->dato;
                delete actual;
                if (this->primero == NULL) {
                    cout<<"Se elimino el ultimo cliente que quedaba"<<endl;
                } 
                cout<<"Cliente encontrado y eliminado: "<<dato.getId()<<endl;
                return dato;
            }
            actual = actual->next;
        } while(actual != this->primero);

        cout<<"Cliente no encontrado"<<endl;
        return dato;
    }
}

void CircularList::mostrarLista() {
    Node actual = this->primero;

    if (actual == NULL) {
        cout<<"No hay nada por mostrar, lista vacia"<<endl;
    } else {
        do {
            cout<<endl<<actual->prev->dato.getId()<<"<-"<<actual->dato.getId()<<"->"<<actual->next->dato.getId()<<endl;
            actual = actual->next;   
        }while (actual != this->primero);
    }
}