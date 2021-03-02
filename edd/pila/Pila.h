#ifndef PILA_H
#define PILA_H

#include "../Nodo.h"

class Pila {
    private:
        Nodo<int>* pila;
    public:
        Pila();
        void push(int);
        int pop();
        void mostrarPila();
};

#endif /*PILA_H*/