#pragma once

#include "Fecha.h"


class RegistroAsistencia
{
public:
    RegistroAsistencia();

    RegistroAsistencia(int idUsuario, int idActividad, Fecha fecha);

    int getIdUsuario();
    int getIdActividad();
    Fecha getFecha();

    void setIdUsuario(int idUsuario);
    void setIdActividad(int idActividad);
    void setFecha(Fecha fecha);

private:

    int _idUsuario;
    int _idActividad;
    Fecha _fecha;
};
