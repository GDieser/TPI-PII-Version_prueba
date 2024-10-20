#pragma once

#include "GestionArchivoEjercicios.h"

class ServicioEjercicio
{
    public:
        ServicioEjercicio();

        void verEjercicio();
        void agregarEjercicio();
        void modificarEjercicio();

    private:

        GestionArchivoEjercicios _archivoEjercicio();
};

