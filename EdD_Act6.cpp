#include <stdio.h>
#include <stdlib.h> // Para malloc y free

int main() 
{
   // int rows, cols;
    int i, j;

/*
    printf("Ingrese el numero de filas: ");
    scanf("%d", &rows);

    printf("Ingrese el numero de columnas: ");
    scanf("%d", &cols);
*/

	int rows=4,cols=4;
   
   // reserva de memoria dinamica con malloc, definido por el tamaño de cada matriz
    int *A= (int*)malloc(rows*cols*sizeof(int)); //matriz A
    int *B= (int*)malloc(rows*cols*sizeof(int)); //matriz B
    int *C= (int*)malloc(rows*cols*sizeof(int)); //matriz  resultante C 

    //llenado de matriz recorriendo el arreglo para A
    printf("\nIngrese los elementos de la matriz A:\n");
    for (i = 0; i < rows; i++) 
	{
        for (j = 0; j < cols; j++) 
		{
            printf("A[%d][%d]: ", i, j); //ubicacion en la matriz a
            scanf("%d", (A + (i * cols + j)));
        }
    }

	//llenado de matriz recorriendo el arreglo para B
    printf("\nIngrese los elementos de la matriz B:\n");
    for (i = 0; i < rows; i++) 
	{
        for (j = 0; j < cols; j++) 
		{
            printf("B[%d][%d]: ", i, j); //ubicacion en la matriz b
            scanf("%d", (B + (i * cols + j)));
        }
    }


    for (i = 0; i < rows; i++) 
	{
        for (j = 0; j < cols; j++) 
		{
            *(C + (i * cols + j)) = *(A + (i * cols + j)) + *(B + (i * cols + j));
        }
    }

    printf("\nResultado de la suma C = A + B:\n"); //resultados de la suma de matrices
    for (i = 0; i < rows; i++)
	{
        for (j = 0; j < cols; j++) 
		{
            printf("%d ", *(C + (i * cols + j)));
        }
        printf("\n");
    }
	//libero memoria para cada variable
    free(A);
    free(B);
    free(C);

    return 0;
}

