#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "datosIniciales/DatosInicialesController.h"

class Controller {
    private:
        DatosInicialesController inicialData;
    public:
        Controller();
        void iniciar();
};

#endif /*CONTROLLER_H*/