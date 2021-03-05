#include <iostream>
#include "FileGenerator.h"

using namespace std;

FileGenerator::FileGenerator(){}

void FileGenerator::generar(Pila* carretas1, Pila* carretas2, Cola* clientesEspera, CircularList* clientesCompra, Cola* clientesPago, LinkedList* cajas) {

    ofstream file("graficas.dot");

    file<<"digraph g {"<<endl;
    file<<"\trankdir = \"LR\";"<<endl;
    file<<"\tlabeljust = \"c\";"<<endl;
    file<<"\tnode[shape=rect,width=1,height=.1];"<<endl;

    generarCajas(&file, cajas);

    generarColaPago(&file, clientesPago);

    generarListaCompras(&file, clientesCompra);

    generarColaEspera(&file, clientesEspera);
    
    generarPilas(&file, carretas1, carretas2);

    file<<"}";

    file.close();
    system("dot -Tpng graficas.dot -o graphic.png");
}

void FileGenerator::generarPilas(ofstream* file, Pila* carretas1, Pila* carretas2) {
    string nodos;

    if (!carretas1->isEmpty() | !carretas2->isEmpty()) {
        *file<<"\tsubgraph ClusterPila {"<<endl;
        *file<<"\t\tnode[shape=record, width=1, height=.1];"<<endl;
        *file<<"\t\tlabel=\"Carretas\";"<<endl;
        nodos = carretas1->getNodos();
        *file<<"\t\tpila1[label=\""+nodos+"\"]"<<endl;
        nodos = carretas2->getNodos();
        *file<<"\t\tpila2[label=\""+nodos+"\"]"<<endl;
        *file<<"\t\tpila1 -> pila2[style=invis];"<<endl;
        *file<<"\t}"<<endl;
    }

}

void FileGenerator::generarColaEspera(ofstream* file, Cola* clientesEspera) {

    if (!clientesEspera->isEmpty()) {
        *file<<"\tsubgraph ClusterColaEspera {"<<endl;
        *file<<"\t\tlabel=\"Cola espera\";"<<endl;
        *file<<clientesEspera->getNodosE();
        *file<<"\t}"<<endl;
    }
}

void FileGenerator::generarColaPago(ofstream* file, Cola* clientesPago) {

    if (!clientesPago->isEmpty()) {
        *file<<"\tsubgraph ClusterColaPago {"<<endl;
        *file<<"\t\tlabel=\"Cola pago\";"<<endl;
        *file<<clientesPago->getNodosP();
        *file<<"\t}"<<endl;
    }
}

void FileGenerator::generarListaCompras(ofstream* file, CircularList* clientesCompras) {

    if (!clientesCompras->isEmpty()) {
        *file<<"\tsubgraph ClusterCompras {"<<endl;
        *file<<"\t\tlabel=\"Compras\";"<<endl;
        *file<<clientesCompras->getNodos();
        *file<<"\t}"<<endl;
    }
}

void FileGenerator::generarCajas(ofstream* file, LinkedList* cajas) {
    
    if (cajas->size() > 0) {
        *file<<"\tsubgraph ClusterCajas {"<<endl;
        *file<<"\t\tlabel=\"Cajas\";"<<endl;
        *file<<cajas->getNodos();
        *file<<"\t}"<<endl;
    }
}