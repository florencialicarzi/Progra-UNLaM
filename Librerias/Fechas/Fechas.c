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
    diasAnio dA= diaDelAnio(f);
    dA.dia += cd;
    int diasARestar = (esBisiesto(dA.anio) ? 366 : 365);
    while(dA.dia > diasARestar)
    {
        dA.dia -= diasARestar;
        dA.anio ++;
        diasARestar = (esBisiesto(dA.anio) ? 366 : 365);
    }
    resultado = convertirFecha(dA);
    return resultado;
}

int difEntreFechas(const Fecha *f1, const Fecha *f2)
{
    int cantDiasAniof1= (esBisiesto(f1->anio) ? 366 : 365);
    int acumuladorDias=0, i=0;
    diasAnio nroDiaf1= diaDelAnio(f1);
    diasAnio nroDiaf2= diaDelAnio(f2);

    if(f1->anio==f2->anio)
    {
        return (nroDiaf2.dia - nroDiaf1.dia);
    }
    acumuladorDias+= (cantDiasAniof1 - nroDiaf1.dia);
    for(i=(nroDiaf1.anio+1);i<nroDiaf2.anio;i++)
    {
        acumuladorDias += (esBisiesto(i) ? 366 : 365);
    }
    acumuladorDias+= nroDiaf2.dia;
    return acumuladorDias;

}


diasAnio diaDelAnio(const Fecha *f)
{
    int i=0;
    diasAnio resultado;
    resultado.dia = f->dia;
    resultado.anio = f->anio;
    for(i=1;i<(f->mes);i++)
    {
        resultado.dia += cantDiasMes(i,resultado.anio);
    }
    return resultado;
}

Fecha convertirFecha(diasAnio dA)
{
    Fecha resultado;
    int cd;
    resultado.dia = dA.dia;
    resultado.mes = 1;
    resultado.anio = dA.anio;
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
