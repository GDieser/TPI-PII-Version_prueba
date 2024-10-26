#pragma once

#include "GestionArchivoSocios.h"

class ServicioSocio
{
public:

    ServicioSocio();

    void verSocios();
    void agregarSocio();
    void modificarSocio();
    void verEntrenadorAsignado(int idSocio);
    void verHorarios();
    void verMembresia(int idSocio);
    void modificarContrasenia(int idSocio);

    bool buscarSocioLogin(int idSocio, std::string pass);
    int obternerUltimoIdSocio();
    int calcularFechaVencimiento();
    void mostrarFechaVencimiento();

    void realizarUnPago(int idSocio);

    bool validarLoginAsistenciaSocio(int idSocio, int pin);
    void asignarEntrenadorASocio();
    void asignarRutinaASocio(int idSocio, int idEntrenador);

    int devolverIdEntrenador(int idSocio);
    int devolverIdRutina(int idSocio);

private:

    GestionArchivoSocios  _archivoSocio;
};


