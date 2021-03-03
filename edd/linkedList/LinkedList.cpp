#include <iostream>
#include "LinkedList.h"

using namespace std;

typedef Nodo<Caja>* Node;

LinkedList::LinkedList(){}

void LinkedList::agregar(Caja caja) {
    Node nuevo = new Nodo<Caja>;
    nuevo->dato = caja;

    if(this->inicio == NULL) {
        this->inicio = nuevo;
    } else {
        Node temp = this->inicio;

        while(temp->next != NULL) {
            temp = temp->next;
        }

        nuevo->prev = temp;
        temp->next = nuevo;
    }
    cout<<"La caja "<<caja.getId()<<" se ha agregado al area de cajas."<<endl;
}

Caja* LinkedList::buscar(int num) {
    Caja* caja;
    Node actual = this->inicio;

    while (actual != NULL) {
        if (actual->dato.getId() == num) {
            caja = &actual->dato;
            return caja;
        }
        actual = actual->next;
    }
    return caja;
}

void LinkedList::mostrarLista() {
    Node actual = this->inicio;

    if (actual == NULL) {
        cout<<"No hay cajas"<<endl;
    } else {
        while (actual != NULL) {
        if (actual->prev == NULL) {
            cout<<endl<<actual->dato.getId()<<"->"<<actual->next->dato.getId()<<endl;
        } else if (actual->next == NULL) {
            cout<<endl<<actual->prev->dato.getId()<<"<-"<<actual->dato.getId()<<endl;
        } else {
            cout<<endl<<actual->prev->dato.getId()<<"<-"<<actual->dato.getId()<<"->"<<actual->next->dato.getId()<<endl;
        }
        actual = actual->next;
    }
    }
}

int LinkedList::isFree() {
    Node actual = this->inicio;
    int free = -1;

    while (actual != NULL) {
        if (actual->dato.getEstado()) {
            free = actual->dato.getId();
            return free;
        }
        actual = actual->next;
    }
    return free;
}