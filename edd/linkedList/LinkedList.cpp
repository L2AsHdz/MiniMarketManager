#include <iostream>
#include "LinkedList.h"

using namespace std;

typedef Nodo<Caja>* Node;

LinkedList::LinkedList(){}

void LinkedList::agregar(Caja caja) {
    Node nuevo = new Nodo<Caja>;
    nuevo->dato = caja;
    nuevo->next = NULL;
    nuevo->prev = NULL;

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

int LinkedList::size() {
    Node actual = this->inicio;
    int size = 0;

    if (actual == NULL) {
        return size;
    } else {
        while (actual != NULL) {
            size++;
            actual = actual->next;
        }
        return size;
    }
}

string LinkedList::getNodos() {
    Node actual = this->inicio;
    string nodos ="";
    string id;
    string estado; 
    string turnos;
    string idNext;
    string idPrev;
    string idCarr;
    string idCli;

    while (actual != NULL) {
        id = to_string(actual->dato.getId());
        turnos = to_string(actual->dato.getTiempoServicio());
        estado = (actual->dato.getEstado())? "libre" : "ocupada" ;

        if (actual->dato.getEstado()) {
            nodos = nodos + "\t\tcaja"+id+"[label = \"Caja "+id+"\\n"+estado+"\\n"+turnos+" turnos\"];\n";
        } else {
            idCli = to_string(actual->dato.getCliente().getId());
            idCarr = to_string(actual->dato.getCliente().getIdCarreta());
            nodos = nodos + "\t\tcaja"+id+"[label = \"Caja "+id+"\\n"+estado+"\\n"+turnos+" turnos\\nCliente "+idCli+"\\nCarreta "+idCarr+"\"];\n";
        }

        actual = actual->next;
    }

    actual = this->inicio;
    while (actual != NULL) {
        
        id = to_string(actual->dato.getId());
        if (actual->prev == NULL) {
            idNext = to_string(actual->next->dato.getId());
            nodos = nodos + "\t\tcaja"+id+" -> caja"+idNext+";\n";
        } else if (actual->next == NULL) {
            idPrev = to_string(actual->prev->dato.getId());
            nodos = nodos + "\t\tcaja"+id+" -> caja"+idPrev+";\n";
        } else {
            idNext = to_string(actual->next->dato.getId());
            idPrev = to_string(actual->prev->dato.getId());
            nodos = nodos + "\t\tcaja"+id+" -> caja"+idNext+";\n";
            nodos = nodos + "\t\tcaja"+id+" -> caja"+idPrev+";\n";
        }

        actual = actual->next;
    }

    return nodos;
}