#ifndef COLA_ESPERA_CONTROLLER_H
#define COLA_ESPERA_CONTROLLER_H

#include "../../edd/pila/Pila.h"
#include "../../edd/cola/Cola.h"
#include "../../edd/circularList/CircularList.h"

class ColaEsperaController {
    private:
        void agregarClienteACompras(CircularList*, int, int);
    public:
        ColaEsperaController();
        void start(Cola*, Pila*, Pila*, CircularList*);
};

#endif /*COLA_ESPERA_CONTROLLER_H*/