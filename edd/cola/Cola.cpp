#include <iostream>
#include "Cola.h"

using namespace std;

typedef Nodo<Cliente>* Node;

Cola::Cola(){}

void Cola::insertar(Cliente cliente) {
    Node nuevo = new Nodo<Cliente>;
    nuevo->dato = cliente;
    nuevo->next = NULL;

    if(this->primero == NULL) {
        this->primero = nuevo;
    } else {
        this->ultimo->next = nuevo;
    }
    this->ultimo = nuevo;
}

Cliente Cola::eliminar() {
    Cliente dato;

    if (this->primero == NULL) {
        cout<<"No hay clientes en la cola"<<endl;
    } else {
        Node temp = this->primero;
        this->primero = temp->next;
        dato = temp->dato;

        delete temp;
        if (this->primero == NULL) this->ultimo = NULL; 
    }
    return dato;
}

void Cola::mostrarCola() {
    Node actual = this->primero;

    if (this->primero == NULL) {
        cout<<"No hay clientes en la cola"<<endl;
    } else {
        while (actual != NULL) {
            cout<<actual->dato.getId()<<" ->";
            actual = actual->next;
        }
    }
}

bool Cola::isEmpty() {
    if (this->primero == NULL) {
        return true;
    } else {
        return false;
    }
}

string Cola::getNodosE() {
    Node actual = this->primero;
    string nodos = "";
    string id;
    string idNext;

    while (actual != NULL) {
        id = to_string(actual->dato.getId());
        nodos = nodos + "\t\tclient"+id+"[label = \"Cliente "+id+"\"];\n";
        actual = actual->next;
    }

    actual = this->primero;
    while (actual != NULL) {
        if (actual->next != NULL) {
            id = to_string(actual->dato.getId());
            idNext = to_string(actual->next->dato.getId());
            nodos = nodos + "\t\tclient"+id+" -> client"+idNext+";\n";
        }
        actual = actual->next;
    }

    return nodos;
}

string Cola::getNodosP() {
    Node actual = this->primero;
    string nodos = "";
    string id;
    string idNext;

    while (actual != NULL) {
        id = to_string(actual->dato.getId());
        nodos = nodos + "\t\tclientP"+id+"[label = \"Cliente "+id+"\"];\n";
        actual = actual->next;
    }

    actual = this->primero;
    while (actual != NULL) {
        if (actual->next != NULL) {
            id = to_string(actual->dato.getId());
            idNext = to_string(actual->next->dato.getId());
            nodos = nodos + "\t\tclientP"+id+" -> clientP"+idNext+";\n";
        }
        actual = actual->next;
    }

    return nodos;
}