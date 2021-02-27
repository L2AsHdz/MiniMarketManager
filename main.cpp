#include <iostream>
#include "EDD/Pila/Pila.h"

using namespace std;

void mostrarMenu();
void eleccion(int);

Pila pila = Pila();

int main() {
    int opcion;

    do {
        mostrarMenu();
        cin>>opcion;
        eleccion(opcion);
    } while (opcion != 4);


    return 1;
}

void mostrarMenu(){
    cout<<"\n1. Push"<<endl;
    cout<<"2. Pop"<<endl;
    cout<<"3. MostrarPila"<<endl;
    cout<<"4. Salir"<<endl;
}

void eleccion(int opcion){
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