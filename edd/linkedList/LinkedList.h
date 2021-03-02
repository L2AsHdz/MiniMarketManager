#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "../Nodo.h"

class LinkedList {
    private:
        Nodo* inicio;
    public:
        LinkedList();
        void agregar(int dato);
        int buscar(int num);
        void mostrarLista();
};

#endif /*LINKED_LIST_H*/