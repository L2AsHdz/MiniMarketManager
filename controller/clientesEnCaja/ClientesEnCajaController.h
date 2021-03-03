#ifndef CLIENTES_EN_CAJA_CONTROLLER_H
#define CLIENTES_EN_CAJA_CONTROLLER_H

#include "../../edd/pila/Pila.h"
#include "../../edd/linkedList/LinkedList.h"

class ClientesEnCajaController {
    public:
        ClientesEnCajaController();
        void start(LinkedList*, Pila*, Pila*, int);
};

#endif /*CLIENTES_EN_CAJA_CONTROLLER_H*/