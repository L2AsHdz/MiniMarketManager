#ifndef CAJA_H
#define CAJA_H

#include "../cliente/Cliente.h"

class Caja {
    private:
        int id;
        int tiempoServicio;
        bool estado;
        Cliente cliente;
    public:
        Caja();
        Caja(int);
        int getId();
        void aumentarServicio();
        int getTiempoServicio();
        void setEstado(bool);
        bool getEstado();
        void setCliente(Cliente);
        Cliente getCliente();
};

#endif /*CAJA_HS*/