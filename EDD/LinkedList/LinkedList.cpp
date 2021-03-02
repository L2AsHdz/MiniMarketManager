#include <iostream>
#include "LinkedList.h"

using namespace std;

typedef Nodo* Node;

LinkedList::LinkedList(){}

void LinkedList::agregar(int dato) {
    Node nuevo = new Nodo;
    nuevo->dato = dato;

    if(this->inicio == NULL) {
        this->inicio = nuevo;
        cout<<"Elemento "<<dato<<" agregado al inicio"<<endl;
    } else {
        Node temp = this->inicio;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        nuevo->prev = temp;
        temp->next = nuevo;
        cout<<"Elemento "<<dato<<" agregado a la lista"<<endl;
    }
}

int LinkedList::buscar(int num) {
    Node actual = this->inicio;

    while (actual != NULL) {
        if (actual->dato == num) {
            cout<<"Numero encontrado"<<endl;
            return num;
        }
        actual = actual->next;
    }

    cout<<"No se encontro el numero"<<endl;
    return -1;
}

void LinkedList::mostrarLista() {
    Node actual = this->inicio;

    if (actual == NULL) {
        cout<<"Lista vacia, imposible imprimir"<<endl;
    } else {
        while (actual != NULL) {
        if (actual->prev == NULL) {
            cout<<endl<<actual->dato<<"->"<<actual->next->dato<<endl;
        } else if (actual->next == NULL) {
            cout<<endl<<actual->prev->dato<<"<-"<<actual->dato<<endl;
        } else {
            cout<<endl<<actual->prev->dato<<"<-"<<actual->dato<<"->"<<actual->next->dato<<endl;
        }
        actual = actual->next;
    }
    }
}