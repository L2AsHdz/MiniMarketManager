#include "../Nodo.h"

class CircularList{
    private:
        Nodo* inicio;
    public:
        CircularList();
        void agregar(int dato);
        int eliminar(int num);
        void mostrarLista();
};