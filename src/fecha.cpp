#include "../include/fecha.h"

struct rep_fecha
{
    /************ Parte 2.1 ************/
    /*Escriba el código a continuación */
    nat dia, mes, anio;

    /****** Fin de parte Parte 2.1 *****/
};

TFecha crearTFecha(nat dia, nat mes, nat anio)
{
    TFecha nuevaFecha = NULL;
    /************ Parte 3.1 ************/
    /*Escriba el código a continuación */
    nuevaFecha = new rep_fecha;
    nuevaFecha->dia = dia;
    nuevaFecha->mes = mes;
    nuevaFecha->anio = anio;
    /****** Fin de parte Parte 3.1 *****/
    return nuevaFecha;
}

void liberarTFecha(TFecha &fecha)
{
    /************ Parte 3.3 ************/
    /*Escriba el código a continuación */
    delete fecha;
    fecha = NULL;
    /****** Fin de parte Parte 3.3 *****/
}
void imprimirTFecha(TFecha fecha)
{
    /************ Parte 3.5 ************/
    /*Escriba el código a continuación */
    printf("%d/%d/%d\n", fecha->dia, fecha->mes, fecha->anio);
    /****** Fin de parte Parte 3.5 *****/
}

/************ Parte 3.9 ************/
/*Escriba el código a continuación */
/*Recuerde que las funciones auxiliares
  deben declararse antes de ser utilizadas*/

nat diasMes(nat mes, nat anio)
{
    switch (mes)
    {
    case 1:
        return 31;
    case 2:
        return ((!(anio % 100) == 0) & ((anio % 4) == 0)) || ((anio % 400) == 0) ? 29 : 28;
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    default:
        return 31;
    };
}
void aumentarTFecha(TFecha &fecha, nat dias)
{

    fecha->dia += dias;
    while (fecha->dia > diasMes(fecha->mes, fecha->anio))
    {
        fecha->dia -= diasMes(fecha->mes, fecha->anio);
        fecha->mes++;
        if (fecha->mes > 12)
        {
            fecha->mes = 1;
            fecha->anio++;
        }
    }
}

/****** Fin de parte Parte 3.9 *****/

// Si fecha1 es mayor que fecha2 retorna 1, si es menor retorna -1,
// si son iguales retorna 0

int compararTFechas(TFecha fecha1, TFecha fecha2)
{
    int res = 0;
    /************ Parte 3.10 ************/
    /*Escriba el código a continuación */
    nat f1 = fecha1->anio * 10000 + fecha1->mes * 100 + fecha1->dia;
    nat f2 = fecha2->anio * 10000 + fecha2->mes * 100 + fecha2->dia;
    res = f1 > f2 ? 1 : f2 > f1 ? -1
                                : 0;
    /****** Fin de parte Parte 3.10 ***/
    return res;
}
