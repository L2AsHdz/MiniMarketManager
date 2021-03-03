#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "datosIniciales/DatosInicialesController.h"
#include "agregarClientes/AddClientesController.h"
#include "colaEspera/ColaEsperaController.h"
#include "areaCompras/AreaComprasController.h"

class Controller {
    private:
        DatosInicialesController inicialData;
        AddClientesController addCliente;
        ColaEsperaController colaEspera;
        AreaComprasController areaCompras;

        //Pilas para las carretas
        Pila pilaCarretas1;
        Pila pilaCarretas2;
        //Cola de espera de clientes
        Cola clientesEnEspera;
        //Lista circular para clientes comprando
        CircularList clientesComprando;
        //Cola de espera para pagar
        Cola clientesEsperaPago;
        //LinkedList para las cajas
        LinkedList cajas;

        void ejecutarPasoSiguiente();
        void agregarClientesNuevos();
        void verificarColaEspera();
        void verificarAreaCompras();
    public:
        Controller();
        void iniciar();
};

#endif /*CONTROLLER_H*/