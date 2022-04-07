#include <stdio.h>
#include <stdlib.h>
#include "../../Librerias/Fechas/Fechas.h"

int main()
{
    int cd=0;
    Fecha f,f1,f2;
    Fecha resultado;
    int res=0;

    printf("Ingrese el dd/mm/aaaa: \n");
    scanf("%d/%d/%d", &f.dia,&f.mes,&f.anio);
    printf("VALIDAR FECHA\n");
    if(esFechaValida(f)==0)
    {
        printf("La fecha es valida\n");
    }else{
        printf("La fecha no es valida\n");
    }

    printf("\nIngrese cant de dias a sumar a la fecha:");
    scanf("%d",&cd);
    resultado = sumarDiasAFechas(&f,cd);
    printf("\nla fecha es: %d/%d/%d", resultado.dia, resultado.mes, resultado.anio);

    printf("Ingrese la primer fecha dd/mm/aaaa:");
    scanf("%d/%d/%d", &f1.dia,&f1.mes,&f1.anio);
    printf("\nIngrese la segunda fecha dd/mm/aaaa:");
    scanf("%d/%d/%d", &f2.dia,&f2.mes,&f2.anio);
    res = difEntreFechas(&f1,&f2);
    printf("\nLa diferencia de dias es de %d", res);

    return 0;
}
