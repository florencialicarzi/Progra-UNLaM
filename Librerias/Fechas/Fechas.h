#ifndef FECHAS_H_INCLUDED
#define FECHAS_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;
}Fecha;

typedef struct{
    int dia;
    int anio;
}diasAnio;


int esFechaValida(Fecha fecha);
Fecha sumarDiasAFechas(const Fecha *f, int cd);
int difEntreFechas(const Fecha *f1, const Fecha *f2);
diasAnio diaDelAnio(const Fecha *f);
Fecha convertirFecha(diasAnio dA);
int cantDiasMes(int mes, int anio);


#endif // FECHAS_H_INCLUDED
