#include <iostream>
#include <cstring>

#include "ServicioEmpleado.h"
#include "ServicioSocio.h"

using namespace std;


ServicioEmpleado::ServicioEmpleado()
{
    _archivoEmpleado = GestionArchivoEmpleados("archivoEmpleados.dat");
}

void ServicioEmpleado::verEmpleado()
{

}
void ServicioEmpleado::agregarGerenete()
{
    string nombre, apellido, contrasenia;
    int dni, idUsuario;
    int dia, mes, anio;
    Fecha fechaIngreso;
    bool estado = true;
    int idRol = 0, legajo, idTurno, idActividadPrincipal = 0;



    ServicioEmpleado servi;

    system("cls");

    cout << " AGREGAR NUEVO GERENTE: " << endl;
    cout << endl;
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
    cout << " Turno: ";
    cin >> idTurno;
    ///Deberia quedar mas sofisticado el ingreso de la contraseña
    cout << " Ingrese contrasenia: ";
    cin >> contrasenia;


    Fecha fechaNacimiento(dia, mes, anio);

    idUsuario = servi.obternerUltimoId();
    legajo = servi.obternerUltimoLegajo();

    Empleado empleado(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, contrasenia, estado, idRol, legajo, idTurno, idActividadPrincipal);

    system("cls");
    if(_archivoEmpleado.guardarEmpleado(empleado))
    {

        cout << "Gerente ID# " << idUsuario << ", legajo " << legajo << " agregado exitosamente." << endl;
    }
    else
    {
        cout << "Error de ingreso" << endl;
    }

    system("pause");

}

void ServicioEmpleado::agregarEntrenador()
{
    string nombre, apellido, contrasenia;
    int dni, idUsuario;
    int dia, mes, anio;
    Fecha fechaIngreso;
    bool estado = true;
    int idRol = 1, legajo, idTurno, idActividadPrincipal;



    ServicioEmpleado servi;

    system("cls");

    cout << " AGREGAR NUEVO ENTRENADOR: " << endl;
    cout << endl;
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
    cout << " Turno: ";
    cin >> idTurno;
    ///Deberia quedar mas sofisticado el ingreso de la contraseña
    cout << " Ingrese contrasenia: ";
    cin >> contrasenia;


    Fecha fechaNacimiento(dia, mes, anio);

    idUsuario = servi.obternerUltimoId();
    legajo = servi.obternerUltimoLegajo();

    Empleado empleado(nombre, apellido, dni, idUsuario, fechaNacimiento, fechaIngreso, contrasenia, estado, idRol, legajo, idTurno, idActividadPrincipal);

    system("cls");
    if(_archivoEmpleado.guardarEmpleado(empleado))
    {

        cout << "Gerente ID# " << idUsuario <<  ", legajo " << legajo << " agregado exitosamente." << endl;
    }
    else
    {
        cout << "Error de ingreso" << endl;
    }

    system("pause");


}
void ServicioEmpleado::modificarEmpleado()
{

}
void ServicioEmpleado::verSociosAsignados()
{

}
void ServicioEmpleado::asignarHorarios()
{

}
void ServicioEmpleado::verHorariosAsignados()
{

}
void ServicioEmpleado::modificarContrasenia()
{

}

bool ServicioEmpleado::buscarEmpleadoLogin(int idEmpleado, string pass)
{
    Empleado empleado;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    for(int i=0; i < cantidad; i++)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(i);

        if(idEmpleado == empleado.getIdUsuario() && !strcmp(empleado.getContrasenia().c_str(), pass.c_str()))
        {
            return true;
        }
    }

    return false;
}



int ServicioEmpleado::obternerUltimoIdEmpleado()
{
    Empleado empleado;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    if(cantidad > 0)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(cantidad - 1);
        return empleado.getIdUsuario();
    }

    return -1;
}

int ServicioEmpleado::obternerUltimoId()
{
    ServicioSocio socio;

    if(socio.obternerUltimoIdSocio() > obternerUltimoIdEmpleado())
    {
        return socio.obternerUltimoIdSocio()+1;
    }
    else
    {
        return obternerUltimoIdEmpleado()+1;
    }
}

int ServicioEmpleado::obternerUltimoLegajo()
{
    Empleado empleado;

    int cantidad = _archivoEmpleado.cantidadRegistrosEmpleados();

    if(cantidad > 0)
    {
        empleado = _archivoEmpleado.leerRegistroEmpleado(cantidad - 1);
        return empleado.getLegajo()+1;
    }

    return -1;
}
