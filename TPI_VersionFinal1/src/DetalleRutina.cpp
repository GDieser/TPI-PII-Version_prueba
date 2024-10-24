#include <iostream>

#include "DetalleRutina.h"

using namespace std;

DetalleRutina::DetalleRutina()
{
    //ctor
}

DetalleRutina::DetalleRutina(int idEjercicios[], int tam, int idRutina, int repeticiones[], int tam2,  float peso[], int tam3)
{

    setIdEjercicios(idEjercicios, tam);
    setRepeticiones(repeticiones);
    setPeso(peso);

    setIdRutina(idRutina);
}

int DetalleRutina::getIdEjercicios()
{
    return *_idEjercicios;
}
int DetalleRutina::getIdRutina()
{
    return _idRutina;
}
int DetalleRutina::getRepeticiones()
{
    return *_repeticiones;
}
float DetalleRutina::getPeso()
{
    return *_peso;
}

void DetalleRutina::setIdEjercicios(int idEjercicios[], int tam)
{

    for(int i=0; i<10; i++)
    {
        _idEjercicios[i] = idEjercicios[i];
    }

}
void DetalleRutina::setIdRutina(int idRutina)
{
    _idRutina = idRutina;
}
void DetalleRutina::setRepeticiones(int *repeticiones)
{

    *_repeticiones = *repeticiones;

}
void DetalleRutina::setPeso(float *peso)
{

    *_peso = *peso;

}
