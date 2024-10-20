#pragma once

#include "GestionArchivoDetalleRutinas.h"
#include "GestionArchivoRutinas.h"

class ServicioRutina
{
    public:
        ServicioRutina();

        void verRutina();
        void crearRutina();
        void modificarRutina();
        void asignarRutina();

    private:

        GestionArchivoDetalleRutinas _archivoDetallesRutina();
        GestionArchivoRutinas _archivoRutina();
};

