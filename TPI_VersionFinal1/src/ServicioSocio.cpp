#include <iostream>
#include <cstring>

#include "ServicioSocio.h"
#include "Socio.h"
#include "Fecha.h"

#include "ServicioEmpleado.h"
#include "ServicioPago.h"

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

        cout << " Socio ID# " << idUsuario << " agregado exitosamente." << endl;
        cout << endl;
        cout << " Realizar pago..." << endl;
        system("pause");

        realizarUnPago(idUsuario);
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

void ServicioSocio::verMembresia(int idSocio)
{
    system("cls");
    Socio socio;

    int posicion = _archivoSocio.buscarSocio(idSocio);

    socio = _archivoSocio.leerRegistroSocio(posicion);

    cout << "--------------------------" << endl;
    cout << "Membresia actual: ";

    switch(socio.getMembresia())
    {
    case 0:
        cout << "FULL" << endl;
        break;
    case 1:
        cout << "SMART" << endl;
        break;
    case 2:
        cout << "FIT" << endl;
        break;
    }
    cout << "--------------------------" << endl;

    system("pause");
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

int ServicioSocio::calcularFechaVencimiento()
{
    Fecha fechaActual;

    int diasPorMeses[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int fechaDePago = 10;
    int cantidadDeDias;

    if(fechaActual.getDia() > fechaDePago)
    {
        cantidadDeDias = (diasPorMeses[fechaActual.getMes()-1] - fechaActual.getDia()) + fechaDePago;
        return cantidadDeDias;
    }
    else
    {
        return fechaDePago - fechaActual.getDia();
    }

}

void ServicioSocio::mostrarFechaVencimiento()
{
    int dia = calcularFechaVencimiento();
    Fecha fecha;

    system("cls");
    cout << endl;
    cout << "+---------------------------------------+" << endl;
    if(fecha.getDia() > 5)
    {
        cout << "     FECHA DE VENCIMIENTO 10/" << fecha.getMes()+1 << endl;
    }
    else
    {
        cout << "     FECHA DE VENCIMIENTO 10/" << fecha.getMes() << endl;
    }
    cout << endl;
    cout << " Faltan: " << dia << " dias para el vencimiento" << endl;
    cout << "+--------------------------------------+" << endl;

    system("pause");
}

void ServicioSocio::realizarUnPago(int idSocio)
{
    system("cls");

    Socio socio;
    ServicioPago pago;

    int opcion;

    int pos = _archivoSocio.buscarSocio(idSocio);
    socio = _archivoSocio.leerRegistroSocio(pos);
    int idMembresia = socio.getMembresia();

    cout << " Membresia actual: ";
    switch(idMembresia)
    {
    case 0:
        cout << "FULL" << endl;
        break;
    case 1:
        cout << "SMART" << endl;
        break;
    case 2:
        cout << "FIT" << endl;
        break;
    }

    cout << endl;
    cout << " 1 - Confirmar | 2 - Cambiar membresia" << endl;
    cin >> opcion;

    if(opcion == 1)
    {
        pago.registrarPago(idSocio, idMembresia, socio.getFechaDeIngreso());
    }
    else
    {
        cout << " 0 - Full : $55.000 " << endl;
        cout << " 1 - Smart: $35.000 " << endl;
        cout << " 2 - Fit  : $25.000 " << endl;
        cout << endl;
        cout << " Su eleccion: ";
        cin >> idMembresia;

        pago.registrarPago(idSocio, idMembresia, socio.getFechaDeIngreso());
        socio.setMembresia(idMembresia);

        _archivoSocio.guardarSocio(socio, pos);
    }


    system("pause");
}

bool ServicioSocio::validarLoginAsistenciaSocio(int idSocio, int pin)
{
    system("cls");
    Socio socio;


    int cantidad = _archivoSocio.cantidadRegistrosSocios();

    for(int i=0; i<cantidad; i++)
    {
        socio = _archivoSocio.leerRegistroSocio(i);

        if(socio.getIdUsuario() == idSocio && socio.getPinIngreso() == pin)
        {
            return true;
        }
    }

    return false;

    system("pause");
}


