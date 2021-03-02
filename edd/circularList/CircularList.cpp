#include <iostream>
#include "CircularList.h"

using namespace std;

typedef Nodo* Node;

CircularList::CircularList(){}

void CircularList::agregar(int dato) {
    Node nuevo = new Nodo;
    nuevo->dato = dato;

    if (this->primero == NULL) {
        nuevo->next = nuevo;
        nuevo->prev = nuevo;
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
    int dato = -1;

    if (this->primero == NULL) {
        cout<<"Lista vacia, nada por eliminar"<<endl;
        return dato;
    } else {
        Node actual = this->primero;

        do {
            if (actual->dato == num) {

                if (actual == this->primero) {
                    //if (actual == temp->next) {
                    //    cout<<"Es el ultimo en la lista"<<endl;
                    //} else {
                        this->primero = this->primero->next;
                        this->primero->prev = ultimo;
                        this->ultimo->next = this->primero;
                    //}
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
                    cout<<"Se elimino el ultimo elemento que quedaba"<<endl;
                } 
                cout<<"Elemento encontrado y eliminado: "<<dato<<endl;
                return dato;
            }
            actual = actual->next;
        } while(actual != this->primero);

        cout<<"Elemento no encontrado"<<endl;
        return dato;
    }
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