#include <iostream>

#include "ServicioEjercicio.h"
#include "Ejercicio.h"

using namespace std;

ServicioEjercicio::ServicioEjercicio()
{
    _archivoEjercicio = GestionArchivoEjercicios("archivoEjercicios.dat");
}

void ServicioEjercicio::verEjercicios()
{
    system("cls");
    Ejercicio ejercicio;

    int cantidad = _archivoEjercicio.cantidadRegistrosEjercicios();

    for(int i=0; i<cantidad; i++)
    {
        ejercicio = _archivoEjercicio.leerRegistroEjercicio(i);

        cout << "-----------------------------------------------"<< endl;
        cout << " Nombre: " << ejercicio.getNombreEjercicio() << endl;
        cout << " ID #" << ejercicio.getIdEjercicio() << endl;
        cout << " Descripcion: " << ejercicio.getDescripcion() << endl;
    }

    cout << endl;
    system("pause");
}
void ServicioEjercicio::agregarEjercicio()
{
    system("cls");
    string nombre, descripcion;

    cout << " -- Agregar nuevo ejercicio -- " << endl;
    cout << endl;
    cout << " Nombre del Ejercicio: ";
    cin.ignore();
    getline(cin, nombre);
    cout << endl;
    cout << " Descripcion: ";
    getline(cin, descripcion);

    int idEjercicio = obtenerUltimoIdEjercicio();

    Ejercicio ejercicio(idEjercicio, nombre, descripcion);

    if(_archivoEjercicio.guardarEjercicio(ejercicio))
    {
        system("cls");
        cout << "Ejercicio ID #" << idEjercicio << " guardado con exito" << endl;
    }
    else
    {
        cout << "Error de guardado..." << endl;
    }

    system("pause");
}
void ServicioEjercicio::modificarEjercicio()
{
    system("cls");
    Ejercicio ejercicio;
    int idEjercicio;

    string nombre, descripcion;

    cout << " Ingrese ID del ejercicio a modificar: ";
    cin >> idEjercicio;

    int pos = _archivoEjercicio.buscarEjercicio(idEjercicio);

    ejercicio = _archivoEjercicio.leerRegistroEjercicio(pos);

    cout << endl;
    cout << " Nombre: " << ejercicio.getNombreEjercicio() << endl;
    cout << " Descripcion: " << ejercicio.getDescripcion() << endl;
    system("pause");

    system("cls");

    cout << " -- Modificar ejercicio -- " << endl;
    cout << endl;
    cout << " Nombre del Ejercicio: ";
    cin.ignore();
    getline(cin, nombre);
    cout << endl;
    cout << " Descripcion: ";
    getline(cin, descripcion);

    ejercicio.setNombreEjercicio(nombre);
    ejercicio.setDescripcion(descripcion);

    if(_archivoEjercicio.guardarEjercicio(ejercicio, pos))
    {
        cout << endl;
        cout << " Modificacion realizada con exito" << endl;
    }
    else
    {
        cout << "Error de registro..." << endl;
    }

    system("pause");
}

int ServicioEjercicio::obtenerUltimoIdEjercicio() ///Que arranque en 1 y sea autonumerico
{
    int cantidad = _archivoEjercicio.cantidadRegistrosEjercicios();

    if(cantidad != -1)
    {
        return cantidad+1;
    }
    else
    {
        return 1;
    }

}
