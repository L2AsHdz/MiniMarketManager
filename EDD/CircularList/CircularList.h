#include "../Nodo.h"

class CircularList{
    private:
        Nodo* primero;
        Nodo* ultimo;
    public:
        CircularList();
        void agregar(int dato);
        int eliminar(int num);
        void mostrarLista();
};