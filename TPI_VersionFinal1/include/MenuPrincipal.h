#pragma once


class MenuPrincipal
{
public:
    MenuPrincipal();

    void mostrarMenuInicio();
    void mostrarMenuLogin(int &idUsuario, std::string &pass);
    bool verificarLoginSocio(int &idUsuario, std::string &pass);
    bool verificarLoginEmpleado(int &idUsuario, std::string &pass);

protected:

    int _opcion;
};

