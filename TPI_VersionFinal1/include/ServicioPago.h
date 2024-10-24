#pragma once

#include "GestionArchivoPagos.h"

class ServicioPago
{
    public:
        ServicioPago();

        void verRegistroPagosPorSocio(int idSocio);
        void registrarPago(int idSocio, int idMembresia, Fecha periodo);
        void verIngresosAnuales();
        void verIngresosMensuales();

        ///Para saber si ya se realizo el pago del mes
        bool verificarUltimoPagoRealizado(int idSocio);

        void verRegistroPagosPorMes();
        void verRegistroPagosPorAnio();

    private:

        GestionArchivoPagos _archivoPago;
};

