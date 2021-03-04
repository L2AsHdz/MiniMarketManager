#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include <string>
#include "../Nodo.h"
#include "../../model/cliente/Cliente.h"

using namespace std;

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
        string getNodos();

};

#endif /*CIRCULAR_LIST_H*/