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
void ServicioSocio::verEntrenadorAsignado()
{

}
void ServicioSocio::verHorarios()
{

}
void ServicioSocio::verMembresia()
{

}
void ServicioSocio::modificarContrasenia()
{

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
