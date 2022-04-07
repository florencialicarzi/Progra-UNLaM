#include "Funciones.h"

int esFechaValida(int d, int m, int a)
{
    int dias[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if(esBisiesto(a))
    {
      dias[1]=29;
    }
    if(a>1601)
    {
        if(m>1 && m<12)
        {
            if(d>1&&d<dias[m-1])
            {
                return 0;
            }
        }
    }
    return 1;
}
