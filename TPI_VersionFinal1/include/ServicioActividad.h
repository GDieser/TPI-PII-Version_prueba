#pragma once

#include "GestionArchivoActividades.h"

class ServicioActividad
{
public:
    ServicioActividad();

    void listarActividades();
    void agregarActividad();
    void modificarActividad();


private:

    GestionArchivoActividades _archivoActividad;
};


