#include <iostream>

#include "RegistroAsistencia.h"

using namespace std;

RegistroAsistencia::RegistroAsistencia()
{
    //ctor
}

RegistroAsistencia::RegistroAsistencia(int idUsuario, int idActividad, Fecha fecha)
{
    setIdUsuario(idUsuario);
    setIdActividad(idActividad);
    setFecha(fecha);
}

int RegistroAsistencia::getIdUsuario()
{
    return _idUsuario;
}
int RegistroAsistencia::getIdActividad()
{
    return _idActividad;
}

Fecha RegistroAsistencia::getFecha()
{
    return _fecha;
}

void RegistroAsistencia::setIdUsuario(int idUsuario)
{
    _idUsuario = idUsuario;
}
void RegistroAsistencia::setIdActividad(int idActividad)
{
    _idActividad = idActividad;
}

void RegistroAsistencia::setFecha(Fecha fecha)
{
    _fecha = fecha;
}


