#include <iostream>
#include <cstring>

#include "ServicioSocio.h"
#include "Socio.h"
#include "Fecha.h"

#include "ServicioEmpleado.h"

using namespace std;


ServicioSocio::ServicioSocio()
{
    _archivoSocio = GestionArchivoSocios("archivoSocios.dat");
}

void ServicioSocio::verSocios()
{
    system("cls");

    Socio socio;
    int cantidad = _archivoSocio.cantidadRegistrosSocios();

    for(int i=0; i<cantidad; i++)
    {
        socio = _archivoSocio.leerRegistroSocio(i);

        if(socio.getEstado())
        {
            cout << "-------------------------" << endl;
            cout << " Nombre: " << socio.getNombre() << endl;
            cout << " Apellido: " << socio.getApellido() << endl;
            cout << " ID: #" << socio.getIdUsuario() << endl;
            cout << " Membresia: ";

            switch(socio.getMembresia())
            {
            case 0:
                cout << "FIT" << endl;
                break;
            case 1:
                cout << "SMART" << endl;
                break;
            case 2:
                cout << "FULL" << endl;
                break;
            }

            if(socio.getIdEntrenadorAsignado() != 0)
            {
                cout << " Entrenador asignado ID: #" << socio.getIdEntrenadorAsignado() << endl;
            }
            else
            {
                cout << " Sin entrenador Asignado" << endl;
            }
            cout << " Fecha ingreso: " << socio.getFechaDeIngreso().toString() << endl;
        }
    }

    system("pause");
}
void ServicioSocio::agregarSocio()
{
    string nombre, apellido, contrasenia, estadoFisico;
    int dni, idUsuario, idMembresia, pinIngreso;
    int dia, mes, anio;
    Fecha fechaIngreso;
    bool estado = true;
    int idRol = 2, idRutina = 0, idEntrenadorAsignado = 0;



    ServicioEmpleado servi;

    system("cls");

    cout << " AGREGAR NUEVO SOCIO: " << endl;
    cout << " Nombre: ";
    cin >> nombre;
    cout << " Apellido: ";
    cin >> apellido;
    cout << " DNI: ";
    cin >> dni;
    cout << " Dia de nacimiento: ";
    cin >> dia;
    cout << " Mes de nacimiento: ";
    cin >> mes;
    cout << " Anio de nacimiento: ";
    cin >> anio;
    cout << " Estado Fisico: ";
    cin >> estadoFisico;
    cout << " Ingrese contrasenia: ";
    cin >> contrasenia;
    cout << " Ingrese PIN de ingreso: ";
    cin >> pinIngreso;
    cout << " Seleccione tipo de membresia (0-Fit, 1-Smart, 2-Full): ";
    cin >> idMembresia;

    Fecha fechaNacimiento(dia, mes, anio);

    idUsuario = servi.obternerUltimoId();

    Socio socio(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, contrasenia, estado, idRol, idMembresia, estadoFisico, idRutina, idEntrenadorAsignado, pinIngreso);

    system("cls");
    if(_archivoSocio.guardarSocio(socio))
    {

        cout << "Socio ID# " << idUsuario << " agregado exitosamente." << endl;
    }
    else
    {
        cout << "Error de ingreso" << endl;
    }

    system("pause");
}

void ServicioSocio::modificarSocio()
{

}
void ServicioSocio::verEntrenadorAsignado(int idSocio)
{
    system("cls");
    Socio socio;

    int posicion = _archivoSocio.buscarSocio(idSocio);

    socio = _archivoSocio.leerRegistroSocio(posicion);

    cout << "-------------------------" << endl;
    cout << " Socio ID #" << idSocio << endl;
    cout << " Nombre: " << socio.getNombre() << endl;
    cout << " Apellido: " << socio.getApellido() << endl;

    if(socio.getIdEntrenadorAsignado() != 0)
    {
        cout << " Entrenador asignado ID: #" << socio.getIdEntrenadorAsignado() << endl;
    }
    else
    {
        cout << " Sin entrenador Asignado" << endl;
    }

    system("pause");
}

void ServicioSocio::verHorarios()
{

}

void ServicioSocio::verMembresia()
{

}

void ServicioSocio::modificarContrasenia(int idSocio)
{
    system("cls");
    string pass, pass2;
    Socio socio;


    int posicion = _archivoSocio.buscarSocio(idSocio);

    socio = _archivoSocio.leerRegistroSocio(posicion);

    cout << " MODIFICAR CONTRASENIA" << endl;
    cout << "-----------------------------" << endl;
    cout << " Ingrese contrasenia actual: " << endl;
    cin >> pass;

    if(!strcmp(socio.getContrasenia().c_str(), pass.c_str()))
    {
        cout << " Ingrese la nueva contrasenia: " << endl;
        cin >> pass;
        cout << " Repita la nueva contrasenia: " << endl;
        cin >> pass2;
        if(!strcmp(pass.c_str(), pass2.c_str()))
        {
            socio.setContrasenia(pass);
            _archivoSocio.guardarSocio(socio, posicion);
        }
        else
        {
            cout << "Las contrasenias no coinciden" << endl;
            system("pause");
            return;
        }
    }
    else
    {
        cout << "Contrasenia incorrecta" << endl;
        system("pause");
        return;
    }

}

bool ServicioSocio::buscarSocioLogin(int idSocio, string pass)
{
    Socio socio;

    int cantidad = _archivoSocio.cantidadRegistrosSocios();

    for(int i=0; i < cantidad; i++)
    {
        socio = _archivoSocio.leerRegistroSocio(i);

        if(idSocio == socio.getIdUsuario() && !strcmp(socio.getContrasenia().c_str(), pass.c_str()))
        {
            return true;
        }
    }

    return false;
}

int ServicioSocio::obternerUltimoIdSocio()
{
    Socio socio;

    int cantidad = _archivoSocio.cantidadRegistrosSocios();

    if(cantidad > 0)
    {
        socio = _archivoSocio.leerRegistroSocio(cantidad - 1);
        return socio.getIdUsuario();
    }

    return -1;

}
