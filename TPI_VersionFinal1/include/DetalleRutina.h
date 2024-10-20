#pragma once


class DetalleRutina
{
public:
    DetalleRutina();
    DetalleRutina(int idEjercicio, int idRutina, int repeticiones, float peso);

    int getIdEjercicio();
    int getIdRutina();
    int getRepeticiones();
    float getPeso();

    void setIdEjercicio(int idEjercicio);
    void setIdRutina(int idRutina);
    void setRepeticiones(int repeticiones);
    void setPeso(float peso);

private:

    int _idEjercicio;
    int _idRutina;
    int _repeticiones;
    float _peso;
};
