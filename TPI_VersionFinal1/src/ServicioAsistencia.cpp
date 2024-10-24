#include <iostream>

#include "ServicioAsistencia.h"
#include "Fecha.h"
#include "RegistroAsistencia.h"

using namespace std;


ServicioAsistencia::ServicioAsistencia()
{
    _archivoAsitencia = GestionArchivoAsistencias("archivoAsistencias.dat");
}

void ServicioAsistencia::registrarAsistencia(int idSocio)
{
    system("cls");
    Fecha fechaActual;

    if(validarRegistroDeAsistencia(idSocio, fechaActual))
    {
        RegistroAsistencia asistencia(idSocio, fechaActual);

        if(_archivoAsitencia.guardarAsistencia(asistencia))
        {
            cout << " Asistencia registrada con exito" << endl;
        }
        else
        {
            cout << " Error de registro..." << endl;
        }
    }

}

bool ServicioAsistencia::validarRegistroDeAsistencia(int idSocio, Fecha fechaActual)
{
    system("cls");
    RegistroAsistencia asistencia;
    Fecha fecha;

    int cantidad = _archivoAsitencia.cantidadRegistrosAsistencias();

    if(cantidad > 0)
    {
        for(int i=0; i<cantidad; i++)
        {
            asistencia = _archivoAsitencia.leerRegistroAsistencia(i);

            if(asistencia.getIdSocio() == idSocio && fecha.compararSiFechasSonIguales(asistencia.getFecha()))
            {
                return false;
            }
        }
    }
    else
    {
        return true;
    }


    system("pause");
}

void ServicioAsistencia::verAsistenciaPorSocio(int idSocio)
{
    system("cls");
    RegistroAsistencia asistencia;

    int cantidad = _archivoAsitencia.cantidadRegistrosAsistencias();


    for(int i=0; i<cantidad; i++)
    {
        asistencia = _archivoAsitencia.leerRegistroAsistencia(i);

        if(asistencia.getIdSocio() == idSocio)
        {
            cout << "---------------------------" << endl;
            cout << " ID Socio: #" << asistencia.getIdSocio() << endl;
            cout << " Fecha: #" << asistencia.getFecha().toString() << endl;
        }
    }
    system("pause");
}
