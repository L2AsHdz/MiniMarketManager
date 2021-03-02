#include <iostream>
#include "DatosInicialesView.h"

using namespace std;

DatosInicialesView::DatosInicialesView(){}

void DatosInicialesView::bienvenida() {
    cout<<"\n--------------------------------MiniMarket--------------------------------"<<endl;
    cout<<"A continuacion se le solicitaran los datos necesarios para la simulacion"<<endl;
}

int DatosInicialesView::solicitarClientesEnEspera() {
    int cantClientes;
    
    cout<<endl<<"Ingrese la cantidad de clientes en la cola de espera: ";
    cin>>cantClientes;

    return cantClientes;
}

int DatosInicialesView::solicitarNumeroCarretas(int p) {
    int cantCarretas;

    cout<<endl<<"Ingrese la cantidad de carretas en la pila "<<p<<": ";
    cin>>cantCarretas;

    return cantCarretas;
}

int DatosInicialesView::solicitarClientesComprando() {
    int cantClientes;

    cout<<endl<<"Ingrese la cantidad de clientes comprando: ";
    cin>>cantClientes;

    return cantClientes;
}

int DatosInicialesView::solicitarClientesColaPago() {
    int cantClientes;

    cout<<endl<<"Ingrese la cantidad de clientes en la cola de pago ";
    cin>>cantClientes;

    return cantClientes; 
}

int DatosInicialesView::solicitarCantidadCajas() {
    int cantCajas;

    cout<<endl<<"Ingrese la cantidad de cajas ";
    cin>> cantCajas;

    return cantCajas;
}