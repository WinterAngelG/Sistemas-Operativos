#include <stdio.h>

/* a es el numero
   b es la potencia
   c es el numero de sumas que se hace por cada potencia
*/

int potencias(int a, int b, int c)
{
    int aux = a;
    if (b == 1)
    {

        return a;
    }
    else
    {
        for (int i = 1; i < c; i++)
            {
               a += aux; 
            }
            return potencias(a, b-1, c);
    }
}

int main()
{

    printf("El resultado de la potencia es: %d\n\n", potencias(2, 1, 2));  
    return 0;                                                                        
}

