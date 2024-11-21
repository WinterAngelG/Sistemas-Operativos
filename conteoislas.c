#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int filas = 8;
const int col = 6;

void busqueda(int matriz[][col], int visitados[][col], int i, int j){

    if(i < 0 || j < 0 || (i >= filas || j >= col)){return;}

    if(visitados[i][j] || matriz[i][j] == 0){
        return;
    }

    visitados[i][j] = 1;

    busqueda(matriz, visitados, i + 1, j);
    busqueda(matriz, visitados, i - 1, j);
    busqueda(matriz, visitados, i, j + 1);
    busqueda(matriz, visitados, i, j - 1);

}
void llenarMat(int matriz[][col], int visitados[][col]){
    for (int i = 0; i < filas; i++)
    {
       for (int j = 0; j < col; j++)
       {
            matriz[i][j] = rand() % 2;
            visitados[i][j] = 0;
       }
    }
    
}

void imprimir(int matriz[][col]){
    for (int i = 0; i < filas ; i++)
    {
        printf("[");
       for (int j = 0; j < col; j++)
       {
        if(j == col-1){
          printf("%d", matriz[i][j]);
        }else{
            printf("%d,", matriz[i][j]);
        }
            
       }
       printf("]\n");
    }
}

int main(){
    int matriz[filas][col];
    int visitados[filas][col];
    int islas = 0;
    
    llenarMat(matriz, visitados);

    for (int  i = 0; i < filas; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(!visitados[i][j] && matriz[i][j] == 1){
                busqueda(matriz,visitados, i, j);
                islas++;
            }
        }
        
    }

    printf("Matriz de numeros: \n");
    imprimir(matriz);

    printf("Cantidad de islas: %d",islas);

    return 0;
   
}