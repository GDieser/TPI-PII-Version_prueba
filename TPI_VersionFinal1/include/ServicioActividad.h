#pragma once

#include "GestionArchivoActividades.h"

class ServicioActividad
{
public:
    ServicioActividad();

    void listarActividades();
    int agregarActividad();
    void modificarActividad();


private:

    GestionArchivoActividades _archivoActividad;
};


