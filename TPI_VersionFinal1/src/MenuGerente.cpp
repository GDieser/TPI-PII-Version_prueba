#include <iostream>

#include "MenuGerente.h"

#include "ServicioSocio.h"
#include "ServicioEmpleado.h"

using namespace std;


MenuGerente::MenuGerente()
{

}

MenuGerente::MenuGerente(int idGerente)
{
    _idGerenete = idGerente;
}

void MenuGerente::mostrarMenuGerente()
{
    int opcion;

    do
    {
        system("cls");
        cout << " GERENTE: #" << _idGerenete << endl;
        cout << "----------------------------------------" << endl;
        cout << " 1 - GESTIONAR SOCIOS " << endl;
        cout << " 2 - GESTIONAR ENTRENADORES " << endl;
        cout << " 3 - GESTIONAR GERENTE" << endl;
        cout << " 4 - GESTIONAR PAGOS " << endl;
        cout << " 5 - GESTIONAR RECLAMOS " << endl;
        cout << " 6 - VER ESTADISTICAS" << endl;
        cout << "----------------------------------------" << endl;
        cout << " 0 - SALIR " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            gestionarSocios();
            break;
        case 2:
            gestionarEntrenadores();
            break;
        case 3:
            gestionarGerentes();

            break;
        case 4:
            gestionarPagos();

            break;
        case 5:
            gestionarReclamos();

            break;
        case 6:
            verEstadisticas();
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            system("pause");
            break;
        }

    }
    while(opcion != 0);

}

void MenuGerente::gestionarSocios()
{
    int opcion;
    ServicioSocio socio;

    do
    {
        system("cls");
        cout << " SOCIOS" << endl;
        cout << "----------------------------------------" << endl;
        cout << " 1 - VER LISTA DE SOCIOS ACTIVOS " << endl;
        cout << " 2 - AGREGAR NUEVO SOCIO " << endl;
        cout << " 3 - MODIFICAR SOCIO " << endl;
        cout << " 4 - BUSCAR SOCIO " << endl;
        cout << " 5 - RESTAURAR SOCIO " << endl;
        cout << "----------------------------------------" << endl;
        cout << " 0 - VOLVER ATRAS " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:

            break;
        case 2:
            socio.agregarSocio();
            break;
        case 3:
            socio.modificarSocio();
            break;
        case 4:

            break;
        case 5:

            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            system("pause");
            break;
        }

    }
    while(opcion != 0);

}
void MenuGerente::gestionarEntrenadores()
{
    int opcion;
    ServicioEmpleado entrenador;

    do
    {
        system("cls");
        cout << " ENTRENADORES" << endl;
        cout << "--------------------------------------------" << endl;
        cout << " 1 - VER LISTA DE ENTRENADORES ACTIVOS " << endl;
        cout << " 2 - AGREGAR NUEVO ENTRENADOR " << endl;
        cout << " 3 - MODIFICAR ENTRENADOR " << endl;
        cout << " 4 - BUSCAR ENTRENADOR " << endl;
        cout << " 5 - RESTAURAR ENTRENADOR " << endl;
        cout << " 6 - ASIGNAR HORARIOS " << endl;
        cout << "--------------------------------------------" << endl;
        cout << " 0 - VOLVER ATRAS " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:

            break;
        case 2:
            entrenador.agregarEntrenador();
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            system("pause");
            break;
        }

    }
    while(opcion != 0);

}
void MenuGerente::gestionarGerentes()
{
    int opcion;
    ServicioEmpleado gerente;

    do
    {
        system("cls");
        cout << " GERENTES" << endl;
        cout << "----------------------------------------" << endl;
        cout << " 1 - VER LISTA DE GERENTES " << endl;
        cout << " 2 - AGREGAR NUEVO GERENTE " << endl;
        cout << " 3 - MODIFICAR GERENTE " << endl;
        cout << " 4 - BUSCAR GERENTE " << endl;
        cout << " 5 - RESTAURAR GERENTE " << endl;
        cout << " 6 - CAMBIAR CONTRASENIA " << endl;
        cout << "----------------------------------------" << endl;
        cout << " 0 - VOLVER ATRAS " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:

            break;
        case 2:
            gerente.agregarGerenete();
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            system("pause");
            break;
        }

    }
    while(opcion != 0);

}
void MenuGerente::gestionarPagos()
{
    int opcion;

    do
    {
        system("cls");
        cout << " PAGOS DE SOCIOS " << endl;
        cout << "------------------------------------" << endl;
        cout << " 1 - VER LISTA DE PAGOS PENDIENTES" << endl;
        cout << " 2 - VER LISTA DE PAGOS REALIZADOS" << endl;
        cout << " 3 - VER LISTA DE TIPOS DE PASES " << endl;
        cout << " 4 - LISTA DE DEUDORES" << endl;
        cout << "------------------------------------" << endl;
        cout << " 0 - VOLVER ATRAS " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            system("pause");
            break;
        }

    }
    while(opcion != 0);

}

void MenuGerente::gestionarReclamos()
{
    int opcion;

    do
    {
        system("cls");
        cout << " RECLAMOS" << endl;
        cout << "-------------------------------------------" << endl;
        cout << " 1 - VER LISTA DE RECLAMOS" << endl;
        cout << " 2 - VER LISTA DE RECLAMOS CERRADOS" << endl;
        cout << " 3 - MODIFICAR RECLAMO" << endl;
        cout << "-------------------------------------------" << endl;
        cout << " 0 - VOLVER ATRAS " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            system("pause");
            break;
        }

    }
    while(opcion != 0);

}
void MenuGerente::verEstadisticas()
{
    int opcion;

    do
    {
        system("cls");
        cout << " ESTADISTICAS " << endl;
        cout << "---------------------------------------------" << endl;
        cout << " 1 - VER ESTADISICAS DE INGRESOS" << endl;
        cout << " 2 - VER ESTADISTICA DE PAGOS" << endl;
        cout << " 3 - VER ESTADISICAS DE GANANCIAS" << endl;
        cout << "---------------------------------------------" << endl;
        cout << " 0 - VOLVER ATRAS " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            system("pause");
            break;
        }

    }
    while(opcion != 0);

}
void MenuGerente::modificarContrasenia()
{

}
