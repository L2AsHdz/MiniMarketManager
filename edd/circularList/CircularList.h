#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include "../Nodo.h"

class CircularList{
    private:
        Nodo* primero;
        Nodo* ultimo;
    public:
        CircularList();
        void agregar(int dato);
        int eliminar(int num);
        void mostrarLista();
};

#endif /*CIRCULAR_LIST_H*/