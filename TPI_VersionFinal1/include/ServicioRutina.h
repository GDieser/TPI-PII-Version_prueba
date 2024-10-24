#pragma once

#include "GestionArchivoDetalleRutinas.h"
#include "GestionArchivoRutinas.h"
#include "DetalleRutina.h"

class ServicioRutina
{
    public:
        ServicioRutina();

        void verRutinas(int idEntrenador);
        void crearRutina(int idEntrenador);
        void modificarRutina(int idEntrenador);
        void asignarRutina();

        int obtenerUltimoIdRutina();
        DetalleRutina crearDetalleRutina(int idRutina);
        void verDetallesDeRutina();

    private:

        GestionArchivoDetalleRutinas _archivoDetallesRutina;
        GestionArchivoRutinas _archivoRutina;
};

