#include "matematica.h"
#include <math.h>

double factorial(int n)
{
   int i;
   double fact=1;
   for(i=2;i<=n;i++)
   {
       fact*=i;
   }
   return fact;
}

double redondear(double nro, int cantDec)
{
    double nroTrunco=0, sumaDecimal=0,potenciaNegativa=0, resTrunco=0;
    const float BASE = 10;
    nroTrunco= truncar(nro,cantDec);
    potenciaNegativa= -(cantDec+1);
    sumaDecimal= nro + (5*(pow(BASE,potenciaNegativa)));
    resTrunco= truncar(sumaDecimal,cantDec);
    if(resTrunco>nroTrunco)
    {
        return resTrunco;
    }else
    {
        return nroTrunco;
    }

}

double truncar(double nroTruncar, int decTruncar)
{
    double diezPotenciaN=0,resTruncar=0;
    int parteEntera=0;
    const float BASE= 10;
    if(decTruncar!=0){
        diezPotenciaN=potencia(BASE, decTruncar);
        resTruncar= diezPotenciaN * nroTruncar;
        parteEntera= resTruncar;
        resTruncar=parteEntera/diezPotenciaN;
        return resTruncar;
    }else
    {
        parteEntera=nroTruncar;
        return parteEntera;
    }
}

float potencia(float nroPotencia, int pot)
{
    int i;
    float res=nroPotencia;
    for(i=1; i<pot; i++)
    {
        res*=nroPotencia;
    }
    return res;
}
