#include <iostream>
#include "edd/pila/Pila.h"
#include "edd/cola/Cola.h"
#include "edd/linkedList/LinkedList.h"
#include "edd/circularList/CircularList.h"
#include "model/caja/Caja.h"
#include "model/cliente/Cliente.h"

using namespace std;

void mostrarMenu();
void pilaMenu();
void colaMenu();
void linkedListMenu();
void circularListMenu();

void eleccionMenu(int);
void eleccionPila(int);
void eleccionCola(int);
void eleccionLinkedList(int);
void eleccionCircularList(int);

Pila pila = Pila();
Cola cola = Cola();
LinkedList list = LinkedList();
CircularList circularList = CircularList();

int main() {
    int opcion;

    do {
        mostrarMenu();
        cin>>opcion;
        eleccionMenu(opcion);
    } while (opcion != 5);


    return 1;
}

void mostrarMenu() {
    cout<<"\n1. Cola"<<endl;
    cout<<"2. Pila"<<endl;
    cout<<"3. LinkedList"<<endl;
    cout<<"4. CircularList"<<endl;
    cout<<"5. Salir"<<endl;
}

void pilaMenu() {
    cout<<"\n\n1. Push"<<endl;
    cout<<"2. Pop"<<endl;
    cout<<"3. MostrarPila"<<endl;
    cout<<"4. Regresar"<<endl;
}

void colaMenu() {
    cout<<"\n\n1. Insertar"<<endl;
    cout<<"2. Eliminar"<<endl;
    cout<<"3. MostrarPila"<<endl;
    cout<<"4. Regresar"<<endl;
}

void linkedListMenu() {
    cout<<"\n\n1. Insertar"<<endl;
    cout<<"2. Buscar"<<endl;
    cout<<"3. MostrarPila"<<endl;
    cout<<"4. Regresar"<<endl;
}

void circularListMenu() {
    cout<<"\n\n1. Insertar"<<endl;
    cout<<"2. Eliminar"<<endl;
    cout<<"3. MostrarPila"<<endl;
    cout<<"4. Regresar"<<endl;
}

void eleccionMenu(int opcion) {
    int op;
    
    switch (opcion) {
        case 1:
            do {
                colaMenu();
                cin>>op;
                eleccionCola(op);
            } while (op != 4);
            break;
        case 2:
            do {
                pilaMenu();
                cin>>op;
                eleccionPila(op);
            } while (op != 4);
            break;
        case 3:
            do {
                linkedListMenu();
                cin>>op;
                eleccionLinkedList(op);
            } while(op != 4);
            break;
        case 4:
            do {
                circularListMenu();
                cin>>op;
                eleccionCircularList(op);
            } while(op != 4);
            break;
    }
}

void eleccionPila(int opcion) {
    int dato;

    switch (opcion) {
        case 1:
            cout<<"Ingrese el numero de carreta a agregar ";
            cin>>dato;
            pila.push(dato);
            break;
        case 2:
            pila.pop();
            break;
        case 3:
            pila.mostrarPila();
            break;
    }
}

void eleccionCola(int opcion) {
    int dato;

    switch (opcion) {
        case 1:
            cout<<"Ingrese el id del cliente a agregar ";
            cin>>dato;
            cola.insertar(Cliente(dato));
            break;
        case 2:
            cola.eliminar();
            break;
        case 3:
            cola.mostrarCola();
            break;
    }
}

void eleccionLinkedList(int opcion) {
    int dato;

    switch (opcion) {
        case 1:
            cout<<"Ingrese el id de la caja a agregar ";
            cin>>dato;
            list.agregar(Caja(dato, 1));
            break;
        case 2:
            cout<<"Ingrese el id de la caja a buscar ";
            cin>>dato;
            list.buscar(dato);
            break;
        case 3:
            list.mostrarLista();
            break;
    }
}

void eleccionCircularList(int opcion) {
    int dato;

    switch (opcion) {
        case 1:
            cout<<"Ingrese el id del cliente a agregar ";
            cin>>dato;
            circularList.agregar(Cliente(dato));
            break;
        case 2:
            cout<<"Ingrese el id del cliente a eliminar ";
            cin>>dato;
            circularList.eliminar(dato);
            break;
        case 3:
            circularList.mostrarLista();
            break;
    }
}