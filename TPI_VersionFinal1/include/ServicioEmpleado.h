#pragma once

#include "GestionArchivoEmpleados.h"

class ServicioEmpleado
{
    public:
        ServicioEmpleado();

        ///Necesitamos ambos por que entrenador necesita consultar actividades (podria ser sobrecarga)
        void agregarGerenete();
        void agregarEntrenador();

        void verEntrenadores();
        void verGerentes();

        void modificarEmpleado();
        void verSociosAsignados();
        void asignarHorarios();
        void verHorariosAsignados();
        void modificarContrasenia(int idEmpleado);

        bool buscarEmpleadoLogin(int idSocio, std::string pass);
        int obternerUltimoIdEmpleado();
        int obternerUltimoId();
        int obternerUltimoLegajo();

        bool buscarUnEmpleado(int idEmpleado);

    private:

        GestionArchivoEmpleados _archivoEmpleado;
};

