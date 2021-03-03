#ifndef ADD_CLIENTES_CONTROLLER_H
#define ADD_CLIENTES_CONTROLLER_H

#include "../../edd/pila/Pila.h"
#include "../../edd/cola/Cola.h"
#include "../../edd/circularList/CircularList.h"

class AddClientesController {
    private:
        void agregarClienteACompras(CircularList*, int, int);
    public:
        AddClientesController();
        int start(Pila*, Pila*, Cola*, CircularList*, int, int);
};

#endif /*ADD_CLIENTES_CONTROLLER_H*/