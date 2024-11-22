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
    int maxMemoria;
    int numParticiones;
    int numProceso;
    int tamProceso;
    int tamTotal = 0;

    printf("Ingresa el tamaño de la memoria: (KB): ");
    scanf("%d", &maxMemoria);

    printf("Ingrese la cantidad de particiones:");
    scanf("%d", &numParticiones);

    nodo particiones[numParticiones];
    int length = sizeof(particiones) / sizeof(particiones[0]);

    for (int i = 0; i < numParticiones; i++)
    {
        int tamParticion;
        printf("Ingresa el tamaño de la partición %d: ", i + 1);
        scanf("%d", &tamParticion);
        particiones[i].id = -1;
        particiones[i].tamaño = tamParticion;
        tamTotal += particiones[i].tamaño;
    }

    if (tamTotal > maxMemoria)
    {
        printf("\nSe ha excedido el tamaño maximo en KB de la memoria.Ingrese particiones mas pequeñas\n");
    }
    else
    {
        while (eleccion != 4)
        {
            printf("\n        ||MENU||      ");
            printf("\n\n1.- Asignar proceso");
            printf("\n\n2.- Liberar proceso");
            printf("\n\n3.- Mostrar estado de la memoria\n\n");
            printf("\n\n4.- Salir\n\n");
            printf("\nEleccion:");
            scanf("%d", &eleccion);

            switch (eleccion)
            {
                int bandera;
            case 1:
                bandera = 0;
                printf("\nIngresa el id del proceso: ");
                scanf("%d", &numProceso);

                printf("\nIngresa el tamaño del proceso: ");
                scanf("%d", &tamProceso);

                for (int i = 0; i < length; i++)
                {
                    if (tamProceso <= particiones[i].tamaño && particiones[i].id == -1 && bandera == 0)
                    {

                        particiones[i].id = numProceso;
                        tamProceso = particiones[i].id;
                        printf("Se asigno el proceso %d a la particion %d \n\n", particiones[i].id, i + 1);
                        bandera = 1;
                    }
                }

                if (bandera)
                {
                }
                else
                {
                    printf("\nNo hay espacio en memoria suficiente para asignar\n\n");
                }
                break;

            case 2:
                printf("\nIngresa el id del proceso: \n");
                bandera = 0;
                scanf("%d", &numProceso);
                if (length < 1)
                {
                    printf("No hay procesos cargados en memoria.");
                }
                else
                {
                    for (int i; i < length; i++)
                    {
                        if (particiones[i].id == numProceso)
                        {

                            int aux = particiones[i].id;
                            particiones[i].id = -1;
                            printf("Se libero el proceso con id %d de la partición %d", aux, i + 1);
                            bandera = 1;
                        }
                    }

                    if (!bandera)
                    {
                        printf("No hay proceso con el id ingresado. Intente de nuevo \n\n");
                    }
                }
                bandera = 0;
                break;
            case 3:
                for (int i = 0; i < length; i++)
                {
                    if (particiones[i].id != -1)
                    {
                        printf("\nLa partición %d esta ocupada por el proceso %d\n\n", i + 1, particiones[i].id);
                    }
                    else
                    {
                        printf("La particion %d esta desocupada\n\n", i + 1);
                    }
                }

            case 4:
                bandera = 4;
                break;
            default:
                break;
            }
        }
    }

    return 0;
}