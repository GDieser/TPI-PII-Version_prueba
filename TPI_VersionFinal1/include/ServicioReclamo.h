#pragma once

#include "GestionArchivoReclamos.h"

class ServicioReclamo
{
    public:
        ServicioReclamo();

        void verReclamos(bool resuelto);
        void verReclamoUsusario(int idUsuario);
        void iniciarReclamo(int idUsuario);
        void cambiarEstadoReclamo();

        int obtenerUltimoIdReclamo();

    private:

        GestionArchivoReclamos _archivoReclamos;
};

