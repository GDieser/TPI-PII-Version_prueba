#pragma once


class Ejercicio
{
public:
    Ejercicio();

    Ejercicio(int idEjercicio, std::string nombreEjercicio, std::string descripcion);

    int getIdEjercicio();
    std::string getNombreEjercicio();
    std::string getDescripcion();

    void setIdEjercicio(int idEjercicio);
    void setNombreEjercicio(std::string nombreEjercicio);
    void setDescripcion(std::string descripcion);

private:

    int _idEjercicio;
    char _nombreEjercicio[30];
    char _descripcion[100];
};