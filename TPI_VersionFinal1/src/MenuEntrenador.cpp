#include <iostream>

#include "MenuEntrenador.h"

using namespace std;

MenuEntrenador::MenuEntrenador()
{

}

MenuEntrenador::MenuEntrenador(int idEntrenador)
{
    _idEntrenador = idEntrenador;
}

void MenuEntrenador::mostrarMenuEntrenador()
{
    int opcion;

    do
    {
        system("cls");
        cout << " ENTRENADOR: #" << _idEntrenador << endl;
        cout << "-------------------" <<endl;
        cout << " 1 - HORARIOS " << endl;
        cout << " 2 - RUTINAS " << endl;
        cout << " 3 - RECLAMOS " << endl;
        cout << " 4 - CAMBIAR CONTRASENIA " << endl;
        cout << "-------------------" <<endl;
        cout << " 0 - SALIR " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            verHorariosYSociosAsignados();
            break;
        case 2:
            crearModificarRutina();
            break;
        case 3:
            verReclamos();
            break;
        case 4:
            modificarContrasenia();
            break;
        case 0:
            break;
        default:
            cout << "ERROR" << endl;
            break;
        }

    }
    while(opcion != 0);

}

void MenuEntrenador::verHorariosYSociosAsignados()
{
    int opcion;

    do
    {
        system("cls");
        cout << " HORARIOS " << endl;
        cout << "---------------------------------" <<endl;
        cout << " 1 - VER HORARIOS ASIGNADOS " << endl;
        cout << " 2 - VER SOCIOS ASIGNADOS " << endl;
        cout << "---------------------------------" <<endl;
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

void MenuEntrenador::crearModificarRutina()
{
    int opcion;

    do
    {
        system("cls");
        cout << " RUTINAS " << endl;
        cout << "---------------------------------" <<endl;
        cout << " 1 - VER MIS RUTINAS" << endl;
        cout << " 2 - CREAR UNA RUTINA " << endl;
        cout << " 3 - BUSCAR UNA RUTINA " << endl;
        cout << " 4 - MODIFICAR UNA RUTINA " << endl;
        cout << "---------------------------------" <<endl;
        cout << "0 - VOLVER ATRAS " << endl;
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
        default:
            cout << "Opcion incorrecta" << endl;
            system("pause");
            break;
        }

    }
    while(opcion != 0);

}

void MenuEntrenador::verReclamos()
{
    int opcion;

    do
    {
        system("cls");
        cout << " RECLAMOS " << endl;
        cout << "---------------------------------" <<endl;
        cout << " 1 - REALIZAR UN RECLAMO " << endl;
        cout << " 2 - VER ESTADO DE UN RECLAMOS " << endl;
        cout << "---------------------------------" <<endl;
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


void MenuEntrenador::modificarContrasenia()
{

}
