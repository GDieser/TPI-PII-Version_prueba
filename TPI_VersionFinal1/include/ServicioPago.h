#pragma once

#include "GestionArchivoPagos.h"

class ServicioPago
{
    public:
        ServicioPago();

        void verRegistroPagos();
        void registrarPago();
        void verIngresosAnuales();
        void verIngresosMensuales();

    private:

        GestionArchivoPagos _archivoPago;
};

