#ifndef PILA_H
#define PILA_H

#include "../Nodo.h"
#include <string>

using namespace std;

class Pila {
    private:
        Nodo<int>* pila;
    public:
        Pila();
        void push(int);
        int pop();
        void mostrarPila();
        bool isEmpty();
        string getNodos();
};

#endif /*PILA_H*/