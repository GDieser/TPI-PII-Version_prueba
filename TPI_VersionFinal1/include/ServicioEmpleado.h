#pragma once

#include "GestionArchivoEmpleados.h"

class ServicioEmpleado
{
    public:
        ServicioEmpleado();

        void verEmpleado();

        ///Necesitamos ambos por que entrenador necesita consultar actividades (podria ser sobrecarga)
        void agregarGerenete();
        void agregarEntrenador();

        void modificarEmpleado();
        void verSociosAsignados();
        void asignarHorarios();
        void verHorariosAsignados();
        void modificarContrasenia();

        bool buscarEmpleadoLogin(int idSocio, std::string pass);
        int obternerUltimoIdEmpleado();
        int obternerUltimoId();
        int obternerUltimoLegajo();

    private:

        GestionArchivoEmpleados _archivoEmpleado;
};

