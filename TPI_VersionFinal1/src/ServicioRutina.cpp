#include <iostream>

#include "ServicioRutina.h"
#include "Rutina.h"

using namespace std;


ServicioRutina::ServicioRutina()
{
    _archivoRutina = GestionArchivoRutinas("archivoRutinas.dat");
    _archivoDetallesRutina = GestionArchivoDetalleRutinas("archivoDetalleRutinas.dat");
}

void ServicioRutina::verRutinas(int idEntrenador)
{
    system("cls");
    int *vectPos;
    Rutina rutina;

    int cantidad = _archivoRutina.cantidadRegistrosRutinas();
    int tam =  _archivoRutina.cantidadDeRegistrosPorEntrenador(cantidad, idEntrenador);
    vectPos = new int[tam];
    if(vectPos == nullptr)
    {
        return;
    }

    *vectPos = _archivoRutina.leerRegistrosRutinasPorEntrenador(cantidad, vectPos, tam, idEntrenador);

    for(int i=0; i<tam; i++)
    {
        rutina = _archivoRutina.leerRegistroRutina(vectPos[i]);
        cout << "-----------------------------------------" << endl;
        cout << " Nombre: " << rutina.getNombreRutina() << endl;
        cout << " ID: #" << rutina.getIdRutina() << endl;
        cout << " Descripcion: " << rutina.getDescripcion() << endl;
    }

    cout << endl;

    delete []vectPos;

    system("pause");
}

void ServicioRutina::verDetallesDeRutina()
{
    system("cls");
    int idRutina;

    DetalleRutina detalle;

    cout << " Ingrese ID de Rutina: ";
    cin >> idRutina;

    int pos = _archivoDetallesRutina.buscarDetalleRutina(idRutina);

    if(pos > -1)
    {
        detalle = _archivoDetallesRutina.leerRegistroDetalleRutina(pos);

        int *idEjercicios = detalle.getIdEjercicios();
        int *repeticiones = detalle.getRepeticiones();
        float *peso = detalle.getPeso();

        cout << " ID Rutina: #" << idRutina << endl;

        for(int i=0; i<10; i++)
        {
            if(idEjercicios[i] != 0)
            {
                cout << " ID Ejercicio: #" << idEjercicios[i] << endl;
                cout << " Repeticiones: " << repeticiones[i] << endl;
            }
            if(peso[i] != 0)
            {
                cout << " Peso: " << peso[i] << endl;
            }
        }
    }
    else
    {
        cout << "ID no encontrado..." << endl;
    }


    system("pause");
}

void ServicioRutina::crearRutina(int idEntrenador)
{
    system("cls");
    string nombre, descripcion;
    int frecuencia, idRutina;

    DetalleRutina detalle;

    cout << " -- Crear una nueva Rutina -- " << endl;
    cout << endl;
    cout << "Nombre de la rutina: ";
    cin.ignore();
    getline(cin, nombre);
    cout << "Descripcion de la rutina: ";
    getline(cin, descripcion);
    cout << "Frecuencia semanal: ";
    cin >> frecuencia;

    idRutina = obtenerUltimoIdRutina();

    Rutina rutina(idRutina, frecuencia, idEntrenador, nombre, descripcion);

    if(_archivoRutina.guardarRutina(rutina))
    {
        cout << endl;
        cout << "Rutina agregada exitosamente, ID #" << idRutina <<endl;
        cout << endl;
        cout << "Inicio de carga de detalles de la rutina" << endl;
        system("pause");

        detalle = crearDetalleRutina(idRutina);

        if(_archivoDetallesRutina.guardarDetalleRutina(detalle))
        {
            cout << endl;
            cout << "Detalles agregados exitosamente" << endl;
        }
        else
        {
            cout << endl;
            cout << "Error de registro..." << endl;
        }

    }
    else
    {
        cout << "Error de registro..." << endl;
    }

    system("pause");
}

DetalleRutina ServicioRutina::crearDetalleRutina(int idRutina)
{
    int opcion = 1, contador = 0;
    int idEjercicio[10]= {}, repeticiones[10]= {};
    float peso[10]= {};

    while(contador < 10 && opcion != 0)
    {
        system("cls");

        cout << " -- Detalle de Rutina -- " << endl;
        cout << endl;
        cout << " Ejercicios cargados: " << contador << endl;
        cout << endl;
        cout << " Ingrese ID de Ejercicio: ";
        cin >> idEjercicio[contador];
        cout << " Repeticiones: ";
        cin >> repeticiones[contador];
        cout << " Peso (0 si no aplica): ";
        cin >> peso[contador];

        cout << " Agregar otro ejercicio? 1-SI | 0-NO " << endl;
        cout << " Su eleccion: ";
        cin >> opcion;

        contador++;
    }



    return DetalleRutina(idEjercicio, idRutina, repeticiones, peso);
}

void ServicioRutina::modificarRutina(int idEntrenador)
{
    system("cls");



    system("pause");
}
void ServicioRutina::asignarRutina()
{
    system("cls");


    system("pause");
}

int ServicioRutina::obtenerUltimoIdRutina() ///Que arranque en 1 y sea autonumerico
{
    int cantidad = _archivoRutina.cantidadRegistrosRutinas();

    if(cantidad != -1)
    {
        return cantidad+1;
    }
    else
    {
        return 1;
    }

}
