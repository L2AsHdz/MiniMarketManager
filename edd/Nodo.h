#ifndef NODO_H
#define NODO_H
template <typename T>
struct Nodo {
    T dato;
    Nodo* next;
    Nodo* prev;
};
#endif /*NODO_H*/