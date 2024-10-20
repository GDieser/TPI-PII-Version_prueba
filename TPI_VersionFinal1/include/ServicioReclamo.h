#pragma once

#include "GestionArchivoReclamos.h"

class ServicioReclamo
{
    public:
        ServicioReclamo();

        void verReclamo();
        void verReclamoUsusario();
        void iniciarReclamo();
        void cambiarEstadoReclamo();

    private:

        GestionArchivoReclamos _archivoReclamos();
};

