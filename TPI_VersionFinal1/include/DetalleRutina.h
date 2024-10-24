#pragma once


class DetalleRutina
{
public:
    DetalleRutina();
    DetalleRutina(int idEjercicios[], int tam, int idRutina, int repeticiones[], int tam2,  float peso[], int tam3);

    int getIdEjercicios();
    int getIdRutina();
    int getRepeticiones();
    float getPeso();

    void setIdEjercicios(int idEjercicios[], int tam);
    void setIdRutina(int idRutina);
    void setRepeticiones(int *repeticiones);
    void setPeso(float *peso);

private:

    int _idEjercicios[10];
    int _idRutina;
    int _repeticiones[10];
    float _peso[10];
};
