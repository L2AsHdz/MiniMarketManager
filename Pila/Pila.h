#include "Nodo.h"

class Pila {
    private:
        Nodo* pila = new Nodo;
    public:
        Pila();
        void push(int id);
        int pop();
        void mostrarPila();
};