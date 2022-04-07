#include <stdio.h>
#include <stdlib.h>
#include "../../Librerias/Fechas/Fechas.h"
#include "../../Librerias/matematica/matematica.h"

int main()
{
    int opcionMenu=0;

    int nroFactorial=0;
    double resFactorial=0;

    double nroRedondear=0, resRedondear=0;
    int cantDec=0;

    float nroPotencia=0, resPotencia=0;
    int pot=0;


    double nroTruncar=0, resTruncar=0;
    int decTruncar=0;

    printf("MENU\n 1:Factorial\n 2:Fecha Valida\n 3:Redondeo\n 4:Potencia\n 5:Truncar\n");
    scanf("%d",&opcionMenu);
    system("cls");

    switch(opcionMenu){
        case 1:
                printf("FACTORIZACION\n");
                printf("Ingrese el numero a factorizar: \n");
                scanf("%d", &nroFactorial);
                resFactorial= factorial(nroFactorial);
                printf("El factorial de %d es %1.lf \n\n", nroFactorial,resFactorial);

            break;
        case 2:


            break;
        case 3:
                printf("REDONDEAR UN NUMERO\n");
                printf("Ingrese el numero a redondear.\n");
                scanf("%lf", &nroRedondear);
                printf("Ingrese la cantidad de decimales.\n");
                scanf("%d", &cantDec);
                resRedondear= redondear(nroRedondear,cantDec);
                printf("El numero redondeado es: %lf", resRedondear);

            break;
        case 4:
                printf("POTENCIA\n");
                printf("Ingrese el numero.\n");
                scanf("%f", &nroPotencia);
                printf("Ingrese la potencia.\n");
                scanf("%d", &pot);
                resPotencia=potencia(nroPotencia,pot);
                printf("la potencia es %lf", resPotencia);
            break;

        case 5:
                printf("TRUNCAR UN NUMERO\n");
                printf("Ingrese el numero a Truncar.\n");
                scanf("%lf", &nroTruncar);
                printf("Ingrese la cantidad de decimales.\n");
                scanf("%d", &decTruncar);
                resTruncar= truncar(nroTruncar,decTruncar);
                printf("El numero truncado es: %lf", resTruncar);

            break;

    }

    return 0;
}

