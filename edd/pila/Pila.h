#include "../Nodo.h"

class Pila {
    private:
        Nodo* pila;
    public:
        Pila();
        void push(int id);
        int pop();
        void mostrarPila();
};