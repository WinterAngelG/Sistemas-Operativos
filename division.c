#include <stdio.h>

int main()
{
    int r = division(0,15,0); 
    if(r != -1){
 
        printf("El resultado de la div es: %d\n\n", r);
    }else{

        printf("No se puede dividir entre 0. Intente de nuevo. \n\n");
    }

    return 0;
}

int division(int n, int m, int k)
{
    if (m == 0)
    {
        return -1;
    }
    else
    {

        if ((n - m) <= 0)
        {
            if (n == 0)
            {
                return 0;
            }
            else
            {
                k++;
                return k;
            }
        }
        else
        {

            k++;
            division((n - m), m, k);
        }
    }
}