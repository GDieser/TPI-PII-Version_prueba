#include <iostream>

#include "GestionArchivoReclamos.h"

using namespace std;

GestionArchivoReclamos::GestionArchivoReclamos()
{

}

GestionArchivoReclamos::GestionArchivoReclamos(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool GestionArchivoReclamos::guardarReclamo(Reclamo reclamo)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == nullptr)
    {
        return false;
    }

    guardo = fwrite(&reclamo, sizeof(Reclamo), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

bool GestionArchivoReclamos::guardarReclamo(Reclamo reclamo, int posicion)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return false;
    }

    fseek(pArchivo, sizeof(Reclamo) * posicion, SEEK_SET);

    guardo = fwrite(&reclamo, sizeof(Reclamo), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

int GestionArchivoReclamos::buscarReclamo(int idUsuario)
{
    int posicion = 0;
    Reclamo reclamo;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    while(fread(&reclamo, sizeof(Reclamo), 1, pArchivo))
    {
        if(reclamo.getIdUsuario() == idUsuario)
        {
            fclose(pArchivo);
            return posicion;
        }
        posicion++;
    }

    fclose(pArchivo);

    return -1;
}

Reclamo GestionArchivoReclamos::leerRegistroReclamo(int posicion)
{
    Reclamo reclamo;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return Reclamo();
    }

    fseek(pArchivo, sizeof(Reclamo) * posicion, SEEK_SET);

    fread(&reclamo, sizeof(Reclamo), 1, pArchivo);

    fclose(pArchivo);

    return reclamo;
}

int GestionArchivoReclamos::cantidadRegistrosReclamos()
{
    int cantidad;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    fseek(pArchivo, 0, SEEK_END);

    cantidad = ftell(pArchivo) / sizeof(Reclamo);

    fclose(pArchivo);

    return cantidad;
}

void GestionArchivoReclamos::leerRegistrosReclamo(int cantidadRegistros, Reclamo *vecReclamo)
{
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vecReclamo[i], sizeof(Reclamo), 1, pArchivo);
    }

    fclose(pArchivo);
}
