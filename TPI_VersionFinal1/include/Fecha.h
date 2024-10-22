#pragma once


class Fecha
{
public:
    Fecha();

    Fecha(int dia, int mes, int anio);

    int getDia() const;
    int getMes() const;
    int getAnio() const;

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    void establecerFechaActual();
    void setFechaDefecto();
    void validarFecha();

    bool validarDia();
    bool validarMes();
    bool validarAnio();

    std::string toString();

private:

    int _dia;
    int _mes;
    int _anio;
};
