#pragma once

#include "RegistroPago.h"


class GestionArchivoPagos
{
public:

    GestionArchivoPagos(std::string nombreArchivo);

    bool guardarPago(RegistroPago pago);
    bool guardarPago(RegistroPago pago, int posicion);
    int buscarPago(int idUsuario);
    RegistroPago leerRegistroPago(int posicion);
    int cantidadRegistrosPagos();
    void leerRegistrosPagos(int cantidadRegistros, RegistroPago *vectPago);

    int cantidadDeRegistrosSocios(int cantidadRegistros, int idUsuario);
    int leerRegistrosPagosSocios(int cantidadRegistros, int vectPagos[], int tam, int idUsuario);


private:

    std::string _nombreArchivo;
};
