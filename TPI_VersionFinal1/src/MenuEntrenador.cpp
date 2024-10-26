#include <iostream>

#include "MenuEntrenador.h"
#include "ServicioEmpleado.h"
#include "ServicioReclamo.h"
#include "ServicioEjercicio.h"
#include "ServicioRutina.h"
#include "ServicioSocio.h"

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
    ServicioEmpleado entrenador;

    do
    {
        system("cls");
        cout << " ENTRENADOR: #" << _idEntrenador << endl;
        cout << "-------------------" <<endl;
        cout << " 1 - HORARIOS " << endl;
        cout << " 2 - RUTINAS Y EJERCICIOS" << endl;
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
            entrenador.modificarContrasenia(_idEntrenador);
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
    ServicioEjercicio ejercicio;
    ServicioRutina rutina;
    ServicioSocio socio;

    int opcion, idSocio;

    do
    {
        system("cls");
        cout << " RUTINAS " << endl;
        cout << "---------------------------------" <<endl;
        cout << " 1 - VER MIS RUTINAS" << endl;
        cout << " 2 - VER DETALLES RUTINAS" << endl;
        cout << " 3 - CREAR UNA RUTINA " << endl;
        cout << " 4 - ASIGNAR UNA RUTINA A SOCIO " << endl;
        cout << " 5 - MODIFICAR UNA RUTINA " << endl;
        cout << " 6 - VER EJERCICIOS " << endl;
        cout << " 7 - AGREGAR UN EJERCICIO " << endl;
        cout << " 8 - MODIFICAR UN EJERCICIO " << endl;
        cout << "---------------------------------" <<endl;
        cout << "0 - VOLVER ATRAS " << endl;
        cout << endl;
        cout << " Su seleccion: ";
        cin >> opcion;


        system("cls");
        switch(opcion)
        {
        case 1:
            rutina.verRutinas(_idEntrenador);
            break;
        case 2:
            rutina.verDetallesDeRutina();
            break;
        case 3:
            rutina.crearRutina(_idEntrenador);
            break;
        case 4:
            cout << " Ingrese ID Socio al que desea asignar: ";
            cin >> idSocio;

            socio.asignarRutinaASocio(idSocio, _idEntrenador);

            break;
        case 5:

            break;
        case 6:
            ejercicio.verEjercicios();
            break;
        case 7:
            ejercicio.agregarEjercicio();
            break;
        case 8:
            ejercicio.modificarEjercicio();
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
    ServicioReclamo reclamo;

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
            reclamo.iniciarReclamo(_idEntrenador);
            break;
        case 2:
            reclamo.verReclamoUsusario(_idEntrenador);
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
