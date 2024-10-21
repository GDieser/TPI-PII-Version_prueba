#include <iostream>

#include "MenuPrincipal.h"

#include "Fecha.h"
#include "Empleado.h"
#include "GestionArchivoEmpleados.h"
#include "ServicioActividad.h"

using namespace std;

int main()
{
    /*Fecha fecha(1,1,2000);

    Fecha fecha2;

    Empleado empleado("German", "Dieser", 38123123, 1000, fecha, fecha2, "1234", 1, 0, 1000, 0, 0);

    GestionArchivoEmpleados archi("archivoEmpleados.dat");

    archi.guardarEmpleado(empleado);*/

    //ServicioActividad act;

    //act.agregarActividad();

    MenuPrincipal menu;

    menu.mostrarMenuInicio();

    return 0;
}
