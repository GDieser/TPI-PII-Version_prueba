#pragma once

#include "GestionArchivoSocios.h"

class ServicioSocio
{
public:

    ServicioSocio();

    void verSocios();
    void agregarSocio();
    void modificarSocio();
    void verEntrenadorAsignado();
    void verHorarios();
    void verMembresia();
    void modificarContrasenia();

    bool buscarSocioLogin(int idSocio, std::string pass);
    int obternerUltimoIdSocio();

private:

    GestionArchivoSocios  _archivoSocio;
};


