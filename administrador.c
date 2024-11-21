#include <stdio.h>

typedef struct _nodo
{
    int id;
    int tamaño;

} nodo;

void generar_proceso()
{
}

int main()
{
    int eleccion;
    int tamMemoria;
    int numParticiones;
    int numProceso;
    int tamProceso;
    //int tamTotal;

    printf("Ingresa el tamaño de la memoria: (KB): ");
    scanf("%d", &tamMemoria);

    printf("Ingrese la cantidad de particiones:");
    scanf("%d", &numParticiones);

    nodo particiones[numParticiones];

    for (int i = 0; i < numParticiones; i++)
    {
        int tamParticion;
        printf("Ingresa el tamaño de la partición: %d", i + 1);
        scanf("%d", &tamParticion);
        particiones[i].id = i + 1;
        particiones[i].tamaño = tamParticion;
    }

    printf("        ||MENU||      ");
    printf("1.- Asignar proceso");
    printf("2.- Liberar proceso");
    printf("3.- Mostrar estado de la memoria");
    printf("Eleccion:");
    scanf("%d", &eleccion);

    switch (eleccion)
    {
    case 1:

        printf("Ingresa el id del proceso: ");
        scanf("%d", &numProceso);

        printf("Ingresa el tamaño del proceso");
        scanf("%d", &tamProceso);
        int bandera = 0;

        for (int i = 0; i < 100; i++)
        {
            if (tamProceso <= particiones[i].tamaño && bandera == 0)
            {
                tamProceso = particiones[i].id;
                particiones[i].id = numProceso;
                bandera = 1;
            }
        }

        if (bandera)
        {
            printf("Se asigno el proceso %d a la particion ", tamProceso);
        }
        else
        {
            printf("No hay espacio en memoria suficiente para asignar");
        }
        break;

    default:
        break;
    }

    return 0;
}