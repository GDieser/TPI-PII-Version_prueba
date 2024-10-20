#include <iostream>

#include "MenuPrincipal.h"

#include "MenuSocio.h"
#include "MenuEntrenador.h"
#include "MenuGerente.h"

#include "ServicioSocio.h"
#include "ServicioEmpleado.h"

using namespace std;

MenuPrincipal::MenuPrincipal()
{
    //ctor
}

void MenuPrincipal::mostrarMenuInicio()
{
    int idUsuario;
    string pass;
    bool valido = false;

    cout << "ELIJA TIPO DE USUARIO: " << endl;
    cout << endl;
    cout << " 1 - SOCIO" << endl;
    cout << " 2 - ENTRENADOR" << endl;
    cout << " 3 - GERENTE" << endl;
    cout << endl;
    cout << "Su eleccion: ";

    cin >> _opcion;

    while(valido == false && _opcion > 0 && _opcion < 4)
    {
        mostrarMenuLogin(idUsuario, pass);

        system("cls");
        switch(_opcion)
        {
        case 1:
            valido = verificarLoginSocio(idUsuario, pass);
            break;
        case 2:
            valido = verificarLoginEmpleado(idUsuario, pass);
            break;
        case 3:
            valido = verificarLoginEmpleado(idUsuario, pass);
            break;
        }
    }

    switch(_opcion)
    {
    case 1:
    {
        MenuSocio menuSocio(idUsuario);
        menuSocio.mostrarMenuSocio();
    }

    break;
    case 2:
    {
        MenuEntrenador menuEntrenador(idUsuario);
        menuEntrenador.mostrarMenuEntrenador();
    }

    break;
    case 3:
    {
        MenuGerente menuGerente(idUsuario);
        menuGerente.mostrarMenuGerente();
    }

    break;
    default:
        cout << "Opcion incorrecta" << endl;
        break;
    }

}

void MenuPrincipal::mostrarMenuLogin(int &idUsuario, string &pass)
{
    system("cls");

    cout << "INGRESE ID: ";
    cin >> idUsuario;
    cout << "INGRESE PASS: ";
    cin >> pass;

}

bool MenuPrincipal::verificarLoginSocio(int &idUsuario, string &pass)
{

    ServicioSocio socio;

    if(socio.buscarSocioLogin(idUsuario, pass))
    {
        return true;
    }
    else
    {
        cout << "Login invalido" << endl;
        system("pause");
    }

    return false;
}

bool MenuPrincipal::verificarLoginEmpleado(int &idUsuario, string &pass)
{
    ServicioEmpleado empleado;

    if(empleado.buscarEmpleadoLogin(idUsuario, pass))
    {
        return true;
    }
    else
    {
        cout << "Login invalido" << endl;
        system("pause");
    }

    return false;
}
