#include "Fechas.h"
#define esBisiesto(anio)(((anio)%4==0 &&(anio)%100!=0)||((anio)%400==0))

int esFechaValida(Fecha fecha)
{
    int dias[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(esBisiesto(fecha.anio))
    {
      dias[1]=29;
    }
    if(fecha.anio>=1601)
    {
        if(fecha.mes>0 && fecha.mes<13)
        {
            if(fecha.dia>=1 && fecha.dia<=dias[fecha.mes-1])
            {
                return 0;
            }
        }
    }
    return 1;
}

Fecha sumarDiasAFechas(const Fecha *f, int cd)
{
    Fecha resultado;
    posicionEnAnio posicionF= diaDelAnio(f);
    posicionF.nroDia += cd;
    int diasARestar = (esBisiesto(posicionF.anio) ? 366 : 365);
    while(posicionF.nroDia > diasARestar)
    {
        posicionF.nroDia -= diasARestar;
        posicionF.anio ++;
        diasARestar = (esBisiesto(posicionF.anio) ? 366 : 365);
    }
    resultado = convertirFecha(posicionF);
    return resultado;
}

int difEntreFechas(const Fecha *f1, const Fecha *f2)
{
    int cantDiasAniof1= (esBisiesto(f1->anio) ? 366 : 365);
    int acumuladorDias=0, i=0;
    posicionEnAnio posicionF1= diaDelAnio(f1);
    posicionEnAnio posicionF2= diaDelAnio(f2);

    if(f1->anio==f2->anio)
    {
        return (posicionF2.nroDia - posicionF1.nroDia);
    }
    acumuladorDias+= (cantDiasAniof1 - posicionF1.nroDia);
    for(i=(posicionF1.anio+1);i<posicionF2.anio;i++)
    {
        acumuladorDias += (esBisiesto(i) ? 366 : 365);
    }
    acumuladorDias+= posicionF2.nroDia;
    return acumuladorDias;

}


posicionEnAnio diaDelAnio(const Fecha *f)
{
    int i=0;
    posicionEnAnio resultado;
    resultado.nroDia = f->dia;
    resultado.anio = f->anio;
    for(i=1;i<(f->mes);i++)
    {
        resultado.nroDia += cantDiasMes(i,resultado.anio);
    }
    return resultado;
}

Fecha convertirFecha(posicionEnAnio posicion)
{
    Fecha resultado;
    int cd;
    resultado.dia = posicion.nroDia;
    resultado.mes = 1;
    resultado.anio = posicion.anio;
    while(resultado.dia > (cd = cantDiasMes(resultado.mes, resultado.anio)))
    {
        resultado.dia -= cd;
        resultado.mes++;
    }
    return resultado;
}

int cantDiasMes(int mes, int anio)
{
    int diasMaximo[]={31,28,31,30,31,30,31,31,30,31,30,31};
    if(esBisiesto(anio)==1 && mes==2)
        return 29;
    return diasMaximo[mes-1];
}
