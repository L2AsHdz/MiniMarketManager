#ifndef DATOS_INICIALES_CONTROLLER_H
#define DATOS_INICIALES_CONTROLLER_H

#include <iostream>
#include "../../view/datosIniciales/DatosInicialesView.h"
#include "../../edd/pila/Pila.h"
#include "../../edd/cola/Cola.h"
#include "../../edd/linkedList/LinkedList.h"
#include "../../edd/circularList/CircularList.h"

class DatosInicialesController {
    private:
        DatosInicialesView dataView;
        int cantClientesEspera;
        int cantCarretas1;
        int cantCarretas2;
        int cantClientesComprando;
        int cantClientesColaPago;
        int cantCajas;
        int idCliente;
    public:
        DatosInicialesController();
        void solicitarDatos();
        void inicializarEstructuras(Pila*, Pila*, Cola*, CircularList*, Cola*, LinkedList*);
        int getLastIdCliente();
};

#endif /*DATOS_INCIALES_CONTROLLER_H*/