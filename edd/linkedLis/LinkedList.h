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