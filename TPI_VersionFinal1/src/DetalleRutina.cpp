#include <iostream>

#include "DetalleRutina.h"

using namespace std;

DetalleRutina::DetalleRutina()
{
    //ctor
}

DetalleRutina::DetalleRutina(int idEjercicio, int idRutina, int repeticiones, float peso)
{
    setIdEjercicio(idEjercicio);
    setIdRutina(idRutina);
    setRepeticiones(repeticiones);
    setPeso(peso);
}

int DetalleRutina::getIdEjercicio()
{
    return _idEjercicio;
}
int DetalleRutina::getIdRutina()
{
    return _idRutina;
}
int DetalleRutina::getRepeticiones()
{
    return _repeticiones;
}
float DetalleRutina::getPeso()
{
    return _peso;
}

void DetalleRutina::setIdEjercicio(int idEjercicio)
{
    _idEjercicio = idEjercicio;
}
void DetalleRutina::setIdRutina(int idRutina)
{
    _idRutina = idRutina;
}
void DetalleRutina::setRepeticiones(int repeticiones)
{
    _repeticiones = repeticiones;
}
void DetalleRutina::setPeso(float peso)
{
    _peso = peso;
}
