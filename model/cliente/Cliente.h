#ifndef CLIENTE_H
#define CLIENTE_H
class Cliente {
    private:
        int id;
        int idCarreta;
    public:
        Cliente();
        Cliente(int);
        Cliente(int, int);
        void setId(int);
        int getId();
        void setIdCarreta(int);
        int getIdCarreta();
};
#endif /*CLIENTE_H*/