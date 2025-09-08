#include <stdio.h>
#include <stdlib.h>

//funcion para la matriz en espiral

void SpMtrx(int **matrix, int rows, int cols) 
{
    int arriba = 0, abajo = rows - 1;
    int izq = 0, der = cols - 1;

    while (arriba <= abajo && izq <= der) 
	{
        // de izquierda a derecha
        for (int i = izq; i <= der; i++) 
		{
            printf("%d ", matrix[arriba][i]);
        }
        arriba++;

        // de arriba a abajo
        for (int i = arriba; i <= abajo; i++) 
		{
            printf("%d ", matrix[i][der]);
        }
        der--;

        //de izquierda a derecha
        if (arriba <= abajo) 
		{
            for (int i = der; i >= izq; i--) 
			{
                printf("%d ", matrix[abajo][i]);
            }
            abajo--;
        }

        //abajo a arriba
        if (izq <= der) 
		{
            for (int i = abajo; i >= arriba; i--) 
			{
                printf("%d ", matrix[i][izq]);
            }
            izq++;
        }
    }
}
////////////////////////
int main() 
{
    int rows, cols;
    printf("Ingrese filas y columnas: ");
    scanf("%d %d", &rows, &cols);

    //memoria dinámica
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) 
	{
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }

    // Leer matriz
    printf("Ingrese los elementos de la matriz:\n");
    for (int i = 0; i < rows; i++) 
	{
        for (int j = 0; j < cols; j++) 
		{
            scanf("%d", &matrix[i][j]);
        }
    }

    //mostrar en espiral
    printf("Salida en espiral: ");
    SpMtrx(matrix, rows, cols); //llamada de la funcion enviando parametros
    printf("\n");

    //libera memoria a traves de la recursion de la matriz
    for (int i = 0; i < rows; i++) 
	{
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}

