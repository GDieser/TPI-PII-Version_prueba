#pragma once

#include "Reclamo.h"

class GestionArchivoReclamos
{
    public:

        GestionArchivoReclamos();
        GestionArchivoReclamos(std::string nombreArchivo);

        bool guardarReclamo(Reclamo reclamo);
        bool guardarReclamo(Reclamo reclamo, int posicion);
        int buscarReclamo(int idUsuario);
        Reclamo leerRegistroReclamo(int posicion);
        int cantidadRegistrosReclamos();
        void leerRegistrosReclamo(int cantidadRegistros, Reclamo *vecReclamo);


    private:

        std::string _nombreArchivo;
};
