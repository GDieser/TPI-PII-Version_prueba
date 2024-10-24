#include <iostream>

#include "ServicioPago.h"

using namespace std;

ServicioPago::ServicioPago()
{
    _archivoPago = GestionArchivoPagos("archivoPagos.dat");
}

void ServicioPago::verRegistroPagosPorSocio(int idSocio)
{
    system("cls");
    RegistroPago pago;
    int *vecPago;

    int cantidad = _archivoPago.cantidadRegistrosPagos();

    int cantPagosSocio = _archivoPago.cantidadDeRegistrosSocios(cantidad, idSocio);

    if(cantPagosSocio > 0)
    {
        vecPago = new int[cantPagosSocio];

        *vecPago = _archivoPago.leerRegistrosPagosSocios(cantidad, vecPago, cantPagosSocio, idSocio);

        for(int i=0; i<cantPagosSocio; i++)
        {
            pago = _archivoPago.leerRegistroPago(vecPago[i]);

            cout << " ID #" << pago.getIdUsuario() << endl;
            cout << " Fecha de pago: " << pago.getFechaPago().toString() << endl;
            cout << " Monto: $" << pago.getMonto() << endl;
        }
    }
    else
    {
        cout << "No registra pagos" << endl;
    }

    system("pause");
}
void ServicioPago::registrarPago(int idSocio, int idMembresia, Fecha periodo)
{
    system("cls");

    if(verificarUltimoPagoRealizado(idSocio))
    {
        cout << "PAGO AL DIA" << endl;
        return;
    }

    Fecha fechaActual;
    float monto;

    int mes = fechaActual.getMes();
    periodo.setMes(mes+1);

    switch(idMembresia)
    {
    case 0:
        monto = 55000;
        break;
    case 1:
        monto = 35000;
        break;
    case 2:
        monto = 25000;
        break;
    }

    RegistroPago pago(idSocio, monto, periodo, fechaActual);

    if(_archivoPago.guardarPago(pago))
    {
        cout << "-------------------------------------------" << endl;
        cout << "- Pago Realizado con exito." << endl;
        cout << "- Proxima fecha de vencimiendo: " << periodo.toString() << endl;
        cout << "-------------------------------------------" << endl;
    }
    else
    {
        cout << "Error al procesar el pago..." << endl;
    }

    system("pause");
}

bool ServicioPago::verificarUltimoPagoRealizado(int idSocio)
{
    system("cls");
    Fecha fechaActual;

    RegistroPago pago;

    int cantidad = _archivoPago.cantidadRegistrosPagos();
    int pos = _archivoPago.ultimoRegistroSocio(cantidad, idSocio);

    if(pos != -1)
    {
        pago = _archivoPago.leerRegistroPago(pos);

        if(pago.getPeriodo().getMes() > fechaActual.getMes())
        {
            return true;
        }
        else if((pago.getPeriodo().getDia() - fechaActual.getDia()) > 10 )
        {
            return true;
        }
    }

    return false;

    system("pause");
}

void ServicioPago::verRegistroPagosPorMes()
{
    system("cls");
    RegistroPago pago;
    int mes, anio;

    int contador = 0;

    cout << "---------------------------" << endl;
    cout << " Ingrese Anio: ";
    cin >> anio;
    cout << " Ingrese mes: ";
    cin >> mes;

    int cantidad = _archivoPago.cantidadRegistrosPagos();

    for(int i=0; i<cantidad; i++)
    {
        pago = _archivoPago.leerRegistroPago(i);

        if(pago.getFechaPago().getAnio() == anio && pago.getFechaPago().getMes() == mes)
        {
            system("cls");
            cout << "-------------------------------------------" << endl;
            cout << " ID Socio: #" << pago.getIdUsuario() << endl;
            cout << " Fecha: " << pago.getFechaPago().toString() << endl;
            cout << " Monto: $" << pago.getMonto() << endl;

            contador++;
        }

    }

    if(contador == 0)
    {
        cout << "No se econtraron registros..." << endl;
    }

    system("pause");
}

void ServicioPago::verRegistroPagosPorAnio()
{
    system("cls");
    RegistroPago pago;
    int mes, anio;

    int contador = 0;

    cout << "---------------------------" << endl;
    cout << " Ingrese Anio: ";
    cin >> anio;

    int cantidad = _archivoPago.cantidadRegistrosPagos();

    for(int i=0; i<cantidad; i++)
    {
        pago = _archivoPago.leerRegistroPago(i);

        if(pago.getFechaPago().getAnio() == anio)
        {
            system("cls");
            cout << "-------------------------------------------" << endl;
            cout << " ID Socio: #" << pago.getIdUsuario() << endl;
            cout << " Fecha: " << pago.getFechaPago().toString() << endl;
            cout << " Monto: $" << pago.getMonto() << endl;

            contador++;
        }

    }

    if(contador == 0)
    {
        cout << "No se econtraron registros..." << endl;
    }

    system("pause");
}

void ServicioPago::verIngresosAnuales()
{
    system("cls");
    RegistroPago pago;

    float vectorMeses[12] {};
    float total = 0;

    int anio;

    int contador = 0;

    cout << "------------------------------------" << endl;
    cout << " Ingrese Anio de consulta: ";
    cin >> anio;

    int cantidad = _archivoPago.cantidadRegistrosPagos();

    for(int i=0; i<cantidad; i++)
    {
        pago = _archivoPago.leerRegistroPago(i);

        if(pago.getFechaPago().getAnio() == anio)
        {
            vectorMeses[pago.getFechaPago().getMes()-1] += pago.getMonto();
            total += pago.getMonto();
            contador++;
        }
    }
    if(contador == 0)
    {
        system("cls");
        cout << "No se econtraron registros..." << endl;
        system("pause");
        return;
    }

    cout << "------------------------------------" << endl;
    cout << " MES             ||       INGRESOS" << endl;
    cout << "------------------------------------" << endl;
    for(int i=0; i<12; i++)
    {
        if(vectorMeses[i] != 0)
        {
            switch(i)
            {
            case 0:
                cout << " ENERO           ||   $" << vectorMeses[i] << endl;
                break;
            case 1:
                cout << " FEBRERO         ||   $" << vectorMeses[i] << endl;
                break;
            case 2:
                cout << " MARZO           ||   $" << vectorMeses[i] << endl;
                break;
            case 3:
                cout << " ABRIL           ||   $" << vectorMeses[i] << endl;
                break;
            case 4:
                cout << " MAYO            ||   $" << vectorMeses[i] << endl;
                break;
            case 5:
                cout << " JUNIO           ||   $" << vectorMeses[i] << endl;
                break;
            case 6:
                cout << " JULIO           ||   $" << vectorMeses[i] << endl;
                break;
            case 7:
                cout << " AGOSTO          ||   $" << vectorMeses[i] << endl;
                break;
            case 8:
                cout << " SEPTIEMBRE      ||   $" << vectorMeses[i] << endl;
                break;
            case 9:
                cout << " OCTUBRE         ||   $" << vectorMeses[i] << endl;
                break;
            case 10:
                cout << " NOVIEMBRE       ||   $" << vectorMeses[i] << endl;
                break;
            case 11:
                cout << " DICIEMBRE       ||   $" << vectorMeses[i] << endl;
                break;
            }
        }

    }
    cout << "------------------------------------" << endl;
    cout << " TOTAL ACUMULADO: " << total << endl;
    cout << "------------------------------------" << endl;

    system("pause");

}
void ServicioPago::verIngresosMensuales()
{
    system("cls");
    RegistroPago pago;
    int mes, anio;

    float montoTotal = 0;

    int contador = 0;

    cout << "---------------------------" << endl;
    cout << " Ingrese Anio: ";
    cin >> anio;
    cout << " Ingrese mes: ";
    cin >> mes;

    int cantidad = _archivoPago.cantidadRegistrosPagos();

    for(int i=0; i<cantidad; i++)
    {
        pago = _archivoPago.leerRegistroPago(i);

        if(pago.getFechaPago().getAnio() == anio && pago.getFechaPago().getMes() == mes)
        {

            montoTotal += pago.getMonto();
            contador++;
        }
    }
    if(contador == 0)
    {
        system("cls");
        cout << "No se econtraron registros..." << endl;
        system("pause");
        return;
    }

    cout << endl;
    cout << "--------------------------------------------" << endl;
    cout << " MES: "<< mes << " || INGRESOS: $" << montoTotal << endl;
    cout << "--------------------------------------------" << endl;

    system("pause");

}
