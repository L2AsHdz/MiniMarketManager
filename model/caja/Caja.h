#ifndef CAJA_H
#define CAJA_H

#include "../cliente/Cliente.h"

class Caja {
    private:
        int id;
        int tiempoServicio;
        int tiempoAtendido;
        bool estado;
        Cliente cliente;
    public:
        Caja();
        Caja(int, int);
        int getId();
        void setServicio(int);
        int getTiempoServicio();
        void aumentarTiempoAtendido();
        void resetTiempoAtendido();
        int getTiempoAtendido();
        void setEstado(bool);
        bool getEstado();
        void setCliente(Cliente);
        Cliente getCliente();
};

#endif /*CAJA_HS*/