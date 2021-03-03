#ifndef ADD_CLIENTES_CONTROLLER_H
#define ADD_CLIENTES_CONTROLLER_H

#include "../../edd/pila/Pila.h"
#include "../../edd/cola/Cola.h"
#include "../../edd/circularList/CircularList.h"

class AddClientesController {
    public:
        AddClientesController();
        void start(Pila*, Pila*, Cola*, CircularList*, int, int);
};

#endif /*ADD_CLIENTES_CONTROLLER_H*/