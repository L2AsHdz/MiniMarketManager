#ifndef AREA_COMPRAS_CONTROLLER_H
#define AREA_COMPRAS_CONTROLLER_H

#include "../../edd/cola/Cola.h"
#include "../../edd/circularList/CircularList.h"
#include "../../edd/linkedList/LinkedList.h"

class AreaComprasController {
    public:
        AreaComprasController();
        void start(CircularList*, Cola*, LinkedList*);
};

#endif /*AREA_COMPRAS_CONTROLLER_H*/