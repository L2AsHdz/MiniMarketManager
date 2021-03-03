#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include "../Nodo.h"
#include "../../model/cliente/Cliente.h"

class CircularList{
    private:
        Nodo<Cliente>* primero;
        Nodo<Cliente>* ultimo;
    public:
        CircularList();
        void agregar(Cliente);
        Cliente eliminar(int);
        void mostrarLista();
        bool isEmpty();
};

#endif /*CIRCULAR_LIST_H*/