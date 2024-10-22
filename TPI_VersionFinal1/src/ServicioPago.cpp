#include <iostream>

#include "ServicioPago.h"

using namespace std;

ServicioPago::ServicioPago()
{
    _archivoPago = GestionArchivoPagos("archivoPagos.dat");
}

void ServicioPago::verRegistroPagos(int idSocio)
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

void ServicioPago::verIngresosAnuales()
{

}
void ServicioPago::verIngresosMensuales()
{

}
