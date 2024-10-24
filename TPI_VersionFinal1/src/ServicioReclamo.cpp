#include <iostream>

#include "ServicioReclamo.h"
#include "Reclamo.h"
#include "Fecha.h"

using namespace std;


ServicioReclamo::ServicioReclamo()
{
    _archivoReclamos = GestionArchivoReclamos("archivoReclamos.dat");
}

void ServicioReclamo::verReclamos(bool resuelto)
{
    system("cls");
    Reclamo reclamo;

    int cantidad = _archivoReclamos.cantidadRegistrosReclamos();

    if(cantidad > 0)
    {
        for(int i=0; i<cantidad; i++)
        {
            reclamo = _archivoReclamos.leerRegistroReclamo(i);

            if(reclamo.getEstaResuelto() == resuelto)
            {
                cout << "-----------------------------------------" << endl;
                cout << " ID Reclamo #" << reclamo.getIdReclamo() << endl;
                cout << " ID Usuario #" << reclamo.getIdUsuario() << endl;
                cout << " Fecha: " << reclamo.getFecha().toString() << endl;
                cout << " Detalle: " << reclamo.getDetalle() << endl;
            }

        }
    }
    else
    {
        cout << " Sin registros..." << endl;
    }

    cout << endl;
    system("pause");
}

void ServicioReclamo::verReclamoUsusario(int idUsuario)
{
    system("cls");
    Reclamo reclamo;
    int *vectReclamos;

    int cantidad = _archivoReclamos.cantidadRegistrosReclamos();
    int tam = _archivoReclamos.cantidadDeRegistrosPorUsuario(cantidad, idUsuario);

    vectReclamos = new int[tam];

    *vectReclamos = _archivoReclamos.leerRegistrosPorUsuario(cantidad, vectReclamos, tam, idUsuario);

    for(int i=0; i<tam; i++)
    {
        reclamo = _archivoReclamos.leerRegistroReclamo(vectReclamos[i]);

        cout << "-------------------------------------------" << endl;
        if(reclamo.getEstaResuelto())
        {
            cout << " Estado del reclamo: RESUELTO" << endl;
        }
        else
        {
            cout << " Estado del reclamo: ACTIVO" << endl;
        }
        cout << " ID #" << reclamo.getIdReclamo() << endl;
        cout << " Detalle: " << reclamo.getDetalle() << endl;
    }

    system("pause");
}
void ServicioReclamo::iniciarReclamo(int idUsuario)
{
    system("cls");
    Fecha fechaActual;
    string detalles;

    cout << " -- Nuevo Reclamo --" << endl;
    cout << endl;
    cout << " Ingrese los detalles: ";

    cin.ignore();/// para ignorar el (\n) del buffer
    getline(cin, detalles);

    int idReclamo = obtenerUltimoIdReclamo();

    Reclamo reclamo(idReclamo, idUsuario, false, detalles, fechaActual);

    if(_archivoReclamos.guardarReclamo(reclamo))
    {
        cout << " Reclamo realizado con exito, ID #" << idReclamo << endl;
        cout << " Fecha: " << fechaActual.toString() << endl;
    }
    else
    {
        cout << " Error al registrar el reclamos..." << endl;
    }

    system("pause");
}

void ServicioReclamo::cambiarEstadoReclamo()
{
    system("cls");
    int idReclamo, opcion;
    Reclamo reclamo;

    cout << " Ingrese ID de Reclamo: ";
    cin >> idReclamo;

    int pos = _archivoReclamos.buscarReclamo(idReclamo);

    if(pos != -1)
    {
        reclamo = _archivoReclamos.leerRegistroReclamo(pos);

        if(reclamo.getEstaResuelto())
        {
            cout << " Estado: RESUELTO" << endl;
            cout << endl;
            cout << " Desea cambiar el estado a ACTIVO: 1-SI | 2-NO" << endl;
            cin >> opcion;
            if(opcion)
            {
                reclamo.setEstaResuelto(false);
                _archivoReclamos.guardarReclamo(reclamo, pos);
            }
        }
        else
        {
            cout << " Estado: ACTIVO" << endl;
            cout << endl;
            cout << " Desea cambiar el estado a RESUELTO: 1-SI | 2-NO" << endl;
            cin >> opcion;
            if(opcion)
            {
                reclamo.setEstaResuelto(true);
                _archivoReclamos.guardarReclamo(reclamo, pos);
            }
        }
    }
    else
    {
        cout << " ID no encontrado..." << endl;
    }

    cout << endl;
    system("pause");
}

///Para autonumerar los IdReclamos, podria empezar en #1
int ServicioReclamo::obtenerUltimoIdReclamo()
{
    int cantidad = _archivoReclamos.cantidadRegistrosReclamos();

    if(cantidad != -1)
    {
        return cantidad+1;
    }
    else
    {
        return 1;
    }

}
