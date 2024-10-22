#pragma once

#include "GestionArchivoPagos.h"

class ServicioPago
{
    public:
        ServicioPago();

        void verRegistroPagos(int idSocio);
        void registrarPago(int idSocio, int idMembresia, Fecha periodo);
        void verIngresosAnuales();
        void verIngresosMensuales();

        ///Para saber si ya se realizo el pago del mes
        bool verificarUltimoPagoRealizado(int idSocio);

    private:

        GestionArchivoPagos _archivoPago;
};

