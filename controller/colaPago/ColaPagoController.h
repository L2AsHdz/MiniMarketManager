#ifndef COLA_PAGO_CONTROLLER_H
#define COLA_PAGO_CONTROLLER_H

#include "../../edd/cola/Cola.h"
#include "../../edd/linkedList/LinkedList.h"

class ColaPagoController {
    public:
        ColaPagoController();
        void start(Cola*, LinkedList*);
};

#endif /*COLA_PAGO_CONTROLLER_H*/