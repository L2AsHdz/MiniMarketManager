#ifndef COLA_H
#define COLA_H

#include <string>
#include "../Nodo.h"
#include "../../model/cliente/Cliente.h"

using namespace std;
class Cola{
    private:
        Nodo<Cliente>* primero;
        Nodo<Cliente>* ultimo;
    public:
        Cola();
        void insertar(Cliente);
        Cliente eliminar();
        void mostrarCola();
        bool isEmpty();
        string getNodosE();
        string getNodosP();
};

#endif /*COLA_H*/