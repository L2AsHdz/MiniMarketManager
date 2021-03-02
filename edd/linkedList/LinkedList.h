#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../Nodo.h"
#include "../../model/caja/Caja.h"

class LinkedList {
    private:
        Nodo<Caja>* inicio;
    public:
        LinkedList();
        void agregar(Caja);
        Caja buscar(int);
        void mostrarLista();
};

#endif /*LINKED_LIST_H*/