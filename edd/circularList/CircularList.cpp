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
    } else {
        this->ultimo->next = nuevo;
        nuevo->prev = this->ultimo;

        this->primero->prev = nuevo;
        nuevo->next = this->primero;
    }
    cout<<"El cliente "<<cliente.getId()<<" ha ingresado al area de compras."<<endl;
    this->ultimo = nuevo;
}

Cliente CircularList::eliminar(int num) {
    Cliente dato;

    if (this->primero == NULL) {
        cout<<"No hay clientes en el area de compras."<<endl;
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
                cout<<"El cliente "<<dato.getId()<<" ha salido del area de compras."<<endl;
                return dato;
            }
            actual = actual->next;
        } while(actual != this->primero);

        return dato;
    }
}

void CircularList::mostrarLista() {
    Node actual = this->primero;

    if (actual == NULL) {
        cout<<"No hay clientes en el area de compras."<<endl;
    } else {
        do {
            cout<<endl<<actual->prev->dato.getId()<<"<-"<<actual->dato.getId()<<"->"<<actual->next->dato.getId()<<endl;
            actual = actual->next;   
        }while (actual != this->primero);
    }
}

bool CircularList::isEmpty() {
    if (this->primero == NULL) {
        return true;
    } else {
        return false;
    }
}