#include <iostream>

#include "MenuSocio.h"
#include "ServicioSocio.h"

using namespace std;

MenuSocio::MenuSocio()
{

}

MenuSocio::MenuSocio(int idSocio)
{
    _idSocio = idSocio;
}

void MenuSocio::mostrarMenuSocio()
{
    int opcion;
    ServicioSocio socio;

    do
    {
        system("cls");
        cout << " MENU SOCIO: #" << _idSocio << endl;
        cout << "-------------------------------" << endl;
        cout << " 1 - PAGOS " << endl;
        cout << " 2 - RUTINAS " << endl;
        cout << " 3 - HORARIOS " << endl;
        cout << " 4 - RECLAMOS " << endl;
        cout << " 5 - CAMBIAR CONTRASENIA " << endl;
        cout << "-------------------------------" << endl;
        cout << " 0 - SALIR " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;

        system("cls");
        switch(opcion)
        {
        case 1:
            realizarPago();
            break;
        case 2:
            verRutina();
            break;
        case 3:
            consultarHorarios();
            break;
        case 4:
            presentarReclamo();
            break;
        case 5:
            socio.modificarContrasenia(_idSocio);
            break;
        case 0:
            cout << "ADIOS!" << endl;
            system("pause");
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }

    }
    while(opcion != 0);

}

void MenuSocio::realizarPago()
{
    int opcion;

    do
    {
        system("cls");
        cout << " PAGOS" << endl;
        cout << "-------------------------------" << endl;
        cout << " 1 - REALIZAR UN PAGO " << endl;
        cout << " 2 - VER PAGOS ANTERIORES " << endl;
        cout << " 3 - VER FECHA DE VENCIMIENTO " << endl;
        cout << " 4 - VER PRECIOS DIFERENTES PASES " << endl;
        cout << "-------------------------------" << endl;
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
            ;
            break;
        case 0:
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }

    }
    while(opcion != 0);

}

void MenuSocio::verRutina()
{
    int opcion;

    do
    {
        system("cls");
        cout << " RUTINAS " << endl;
        cout << "-------------------------------" << endl;
        cout << " 1 - VER RUTINAS DISPONIBLES " << endl;
        cout << " 2 - VER MIS RUTINAS " << endl;
        cout << "-------------------------------" << endl;
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
            cout << "ERROR" << endl;
            break;
        }

    }
    while(opcion != 0);

}

void MenuSocio::consultarHorarios()
{
    int opcion;

    do
    {
        system("cls");
        cout << " HORARIOS" << endl;
        cout << "-----------------------------------------" << endl;
        cout << " 1 - VER HORARIOS DE ENTRENAMIENTOS " << endl;
        cout << " 2 - VER MIS INSCRIPCIONES " << endl;
        cout << " 3 - VER HORARIOS DE APERTURA Y CIERRE " << endl;
        cout << "-----------------------------------------" << endl;
        cout << " 0 - VOLVER ATRAS " << endl;
        cout << endl;
        cout << "Su seleccion: ";
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
            break;
        }

    }
    while(opcion != 0);

}



void MenuSocio::presentarReclamo()
{
    int opcion;

    do
    {
        system("cls");
        cout << " RECLAMOS" << endl;
        cout << "-------------------------------" << endl;
        cout << " 1 - REALIZAR UN RECLAMO " << endl;
        cout << " 2 - VER ESTADO DE UN RECLAMOS " << endl;
        cout << "-------------------------------" << endl;
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
        case 0:
            break;
        default:
            cout << "ERROR" << endl;
            break;
        }

    }
    while(opcion != 0);

}


void MenuSocio::modificarContrasenia()
{

}
