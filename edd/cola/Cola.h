#ifndef COLA_H
#define COLA_H

#include "../Nodo.h"
#include "../../model/cliente/Cliente.h"

class Cola{
    private:
        Nodo<Cliente>* primero;
        Nodo<Cliente>* ultimo;
    public:
        Cola();
        void insertar(Cliente);
        Cliente eliminar();
        void mostrarCola();
};

#endif /*COLA_H*/