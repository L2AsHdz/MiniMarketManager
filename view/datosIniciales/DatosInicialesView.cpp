#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "DatosInicialesView.h"

using namespace std;

DatosInicialesView::DatosInicialesView(){}

void DatosInicialesView::bienvenida() {
    cout<<"\n--------------------------------MiniMarket--------------------------------"<<endl;
    cout<<"A continuacion se le solicitaran los datos necesarios para la simulacion"<<endl;
}

int DatosInicialesView::solicitarClientesEnEspera() {
    char cantClientes[5];
    
    cout<<endl<<"Ingrese la cantidad de clientes en la cola de espera: ";
    cin>>cantClientes;
    while (atoi(cantClientes) == 0) {
        cout<<"Debe ingresar un numero mayor a cero! ";
        cin>>cantClientes;
    }

    return atoi(cantClientes);
}

int DatosInicialesView::solicitarNumeroCarretas(int p) {
    char cantCarretas[5];

    cout<<endl<<"Ingrese la cantidad de carretas en la pila "<<p<<": ";
    cin>>cantCarretas;
    while (atoi(cantCarretas) == 0) {
        cout<<"Debe ingresar un numero mayor a cero! ";
        cin>>cantCarretas;
    }

    return atoi(cantCarretas);
}

int DatosInicialesView::solicitarClientesComprando() {
    char cantClientes[5];

    cout<<endl<<"Ingrese la cantidad de clientes comprando: ";
    cin>>cantClientes;
    while (atoi(cantClientes) == 0) {
        if (strcmp(cantClientes, "0") == 0) {
            break;
        }
        cout<<"Debe ingresar un numero! ";
        cin>>cantClientes;
    }

    return atoi(cantClientes);
}

int DatosInicialesView::solicitarClientesColaPago() {
    char cantClientes[5];

    cout<<endl<<"Ingrese la cantidad de clientes en la cola de pago ";
    cin>>cantClientes;
    while (atoi(cantClientes) == 0) {
        if (strcmp(cantClientes, "0") == 0) {
            break;
        }
        cout<<"Debe ingresar un numero! ";
        cin>>cantClientes;
    }

    return atoi(cantClientes); 
}

int DatosInicialesView::solicitarCantidadCajas() {
    char cantCajas[5];

    cout<<endl<<"Ingrese la cantidad de cajas ";
    cin>> cantCajas;
    while (atoi(cantCajas) == 0) {
        cout<<"Debe ingresar un numero mayor a cero! ";
        cin>>cantCajas;
    }

    return atoi(cantCajas);
}