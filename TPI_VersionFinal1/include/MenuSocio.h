#pragma once

#include "MenuPrincipal.h"

class MenuSocio : public MenuPrincipal
{

public:

    MenuSocio();

    MenuSocio(int idSocio);

    void mostrarMenuSocio();
    void realizarPago();
    void verRutina();
    void consultarHorarios();
    void presentarReclamo();
    void modificarContrasenia();


private:

    int _idSocio;
};
