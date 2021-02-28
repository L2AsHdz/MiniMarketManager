#include <iostream>
#include "EDD/Pila/Pila.h"
#include "EDD/Cola/Cola.h"

using namespace std;

void mostrarMenu();
void pilaMenu();
void colaMenu();
void eleccionPila(int);
void eleccionCola(int);
void eleccionMenu(int);

Pila pila = Pila();
Cola cola = Cola();

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
    cout<<"3. Pila"<<endl;
    cout<<"4. Pila"<<endl;
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
    }
}

void eleccionPila(int opcion) {
    int dato;

    switch (opcion) {
        case 1:
            cout<<"Ingrese el dato a agregar ";
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
            cout<<"Ingrese el dato a agregar ";
            cin>>dato;
            cola.insertar(dato);
            break;
        case 2:
            cola.eliminar();
            break;
        case 3:
            cola.mostrarCola();
            break;
    }
}