#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
#include "../Nodo.h"
#include "../../model/caja/Caja.h"

using namespace std;

class LinkedList {
    private:
        Nodo<Caja>* inicio;
    public:
        LinkedList();
        void agregar(Caja);
        Caja* buscar(int);
        void mostrarLista();
        int isFree();
        int size();
        string getNodos();
};

#endif /*LINKED_LIST_H*/