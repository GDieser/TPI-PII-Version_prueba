#include <iostream>

#include "GestionArchivoEjercicios.h"

using namespace std;

GestionArchivoEjercicios::GestionArchivoEjercicios(string nombreArchivo)
{
    _nombreArchivo = nombreArchivo;
}

bool GestionArchivoEjercicios::guardarEjercicio(Ejercicio ejercicio)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "ab");

    if(pArchivo == nullptr)
    {
        return false;
    }

    guardo = fwrite(&ejercicio, sizeof(Ejercicio), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

bool GestionArchivoEjercicios::guardarEjercicio(Ejercicio ejercicio, int posicion)
{
    bool guardo;
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return false;
    }

    fseek(pArchivo, sizeof(Ejercicio) * posicion, SEEK_SET);

    guardo = fwrite(&ejercicio, sizeof(Ejercicio), 1, pArchivo);

    fclose(pArchivo);

    return guardo;
}

int GestionArchivoEjercicios::buscarEjercicio(int idEjercicio)
{
    int posicion = 0;
    Ejercicio ejercicio;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb+");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    while(fread(&ejercicio, sizeof(Ejercicio), 1, pArchivo))
    {
        if(ejercicio.getIdEjercicio() == idEjercicio)
        {
            fclose(pArchivo);
            return posicion;
        }
        posicion++;
    }

    fclose(pArchivo);

    return -1;
}

Ejercicio GestionArchivoEjercicios::leerRegistroEjercicio(int posicion)
{
    Ejercicio ejercicio;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return Ejercicio();
    }

    fseek(pArchivo, sizeof(Ejercicio) * posicion, SEEK_SET);

    fread(&ejercicio, sizeof(Ejercicio), 1, pArchivo);

    fclose(pArchivo);

    return ejercicio;
}

int GestionArchivoEjercicios::cantidadRegistrosEjercicios()
{
    int cantidad;

    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return -1;
    }

    fseek(pArchivo, 0, SEEK_END);

    cantidad = ftell(pArchivo) / sizeof(Ejercicio);

    fclose(pArchivo);

    return cantidad;
}

void GestionArchivoEjercicios::leerRegistrosEjercicio(int cantidadRegistros, Ejercicio *vecEjercicio)
{
    FILE *pArchivo;

    pArchivo = fopen(_nombreArchivo.c_str(), "rb");

    if(pArchivo == nullptr)
    {
        return;
    }

    for(int i = 0; i < cantidadRegistros; i++)
    {
        fread(&vecEjercicio[i], sizeof(Ejercicio), 1, pArchivo);
    }

    fclose(pArchivo);
}