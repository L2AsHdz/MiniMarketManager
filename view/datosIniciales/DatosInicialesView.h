#ifndef DATOS_INICIALES_VIEW_H
#define DATOS_INICIALES_VIEW_H

class DatosInicialesView {
    public:
        DatosInicialesView();
        void bienvenida();
        int solicitarClientesEnEspera();
        int solicitarNumeroCarretas(int);
        int solicitarClientesComprando();
        int solicitarClientesColaPago();
        int solicitarCantidadCajas();
};

#endif /*DATOS_INICIALES_VIEW_H*/