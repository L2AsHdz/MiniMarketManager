#include "../Nodo.h"

class Cola{
    private:
        Nodo* primero;
        Nodo* ultimo;
    public:
        Cola();
        void insertar(int dato);
        int eliminar();
        void mostrarCola();
};

