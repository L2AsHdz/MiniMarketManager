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

    generarPilas(&file, carretas1, carretas2);
    
    file<<"}";

    file.close();
    system("dot -Tpng graficas.dot -o graphics.png");
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