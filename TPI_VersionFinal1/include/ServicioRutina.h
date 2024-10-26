#pragma once

#include "GestionArchivoDetalleRutinas.h"
#include "GestionArchivoRutinas.h"
#include "DetalleRutina.h"

class ServicioRutina
{
    public:
        ServicioRutina();

        void verRutinas(int idEntrenador);
        void verRutinaAsignada(int idSocio);
        void crearRutina(int idEntrenador);
        void modificarRutina(int idEntrenador);
        void asignarRutina();

        int obtenerUltimoIdRutina();
        DetalleRutina crearDetalleRutina(int idRutina);
        void verDetallesDeRutina();

        void mostrarRutinasPorEntrenador(int idEntrenador);

    private:

        GestionArchivoDetalleRutinas _archivoDetallesRutina;
        GestionArchivoRutinas _archivoRutina;
};

