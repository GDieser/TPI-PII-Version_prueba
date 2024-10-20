#pragma once

#include "GestionArchivoAsistencias.h"

class ServicioAsistencia
{
    public:
        ServicioAsistencia();

        void registrarAsistencia();
        void verAsistencia();

    private:

        GestionArchivoAsistencias _archivoAsitencia();
};

