#include <iostream>
#include "CircularList.h"

using namespace std;

typedef Nodo<Cliente>* Node;

CircularList::CircularList(){}

void CircularList::agregar(Cliente cliente) {
    Node nuevo = new Nodo<Cliente>;
    nuevo->dato = cliente;
    nuevo->next = NULL;
    nuevo->prev = NULL;

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

string CircularList::getNodos() {
    Node actual = this->primero;
    string nodos ="";
    string id;
    string idNext;
    string idPrev;
    string idCarr;

    do {
        id = to_string(actual->dato.getId());
        idCarr = to_string(actual->dato.getIdCarreta());
        nodos = nodos + "\t\tclientC"+id+"[label = \"Cliente "+id+"\\nCarreta "+idCarr+"\"];\n";
        actual = actual->next;
    }while (actual != this->primero);

    actual = this->primero;
    do {
        id = to_string(actual->dato.getId());
        idNext = to_string(actual->next->dato.getId());
        idPrev = to_string(actual->prev->dato.getId());
        if (actual->prev == this->ultimo) {
            nodos = nodos +"\t\tclientC"+id+" -> clientC"+idNext+";\n";
        } else if (actual->next == this->primero) {
            nodos = nodos + "\t\tclientC"+id+" -> clientC"+idPrev+";\n";
            nodos = nodos +"\t\tclientC"+id+" -> clientC"+idNext+"[constraint=false, style=solid, dir=both];\n";
        } else {
            nodos = nodos +"\t\tclientC"+id+" -> clientC"+idNext+";\n";
            nodos = nodos +"\t\tclientC"+id+" -> clientC"+idPrev+";\n";
        }
        actual = actual->next;
    }while (actual != this->primero);

    return nodos;
}