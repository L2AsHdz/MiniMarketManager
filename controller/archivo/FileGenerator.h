#ifndef FILE_GENERATOR_H
#define FILE_GENERATOR_H

#include <fstream>
#include "../../edd/pila/Pila.h"
#include "../../edd/cola/Cola.h"
#include "../../edd/linkedList/LinkedList.h"
#include "../../edd/circularList/CircularList.h"

class FileGenerator {
    private:
        void generarPilas(ofstream*, Pila*, Pila*);
        void generarColaEspera(ofstream*, Cola*);
        void generarColaPago(ofstream*, Cola*);
        void generarListaCompras(ofstream*, CircularList*);
    public:
        FileGenerator();
        void generar(Pila*, Pila*, Cola*, CircularList*, Cola*, LinkedList*);
};

#endif /*FILE_GENERATOR_H*/