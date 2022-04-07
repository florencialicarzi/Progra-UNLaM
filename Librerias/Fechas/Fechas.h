#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct{
    int nroDia; //ex dia
    int anio;
}posicionEnAnio; //ex diasAnio


int esFechaValida(Fecha fecha);
Fecha sumarDiasAFechas(const Fecha *f, int cd);
int difEntreFechas(const Fecha *f1, const Fecha *f2);
posicionEnAnio diaDelAnio(const Fecha *f);
Fecha convertirFecha(posicionEnAnio posicion);
int cantDiasMes(int mes, int anio);


#endif // FECHAS_H_INCLUDED
