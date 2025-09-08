#include <stdio.h>
#include <stdlib.h>

#define MAXEMP 100

// compara ascendente, mediante dos constantes como posiciones consecutivas
int compareAsc(const void *a, const void *b) 
{
    return (*(int *)a - *(int *)b);
}

// compara descendente, mediante dos constantes como posiciones consecutivas
int compareDesc(const void *a, const void *b) 
{
    return (*(int *)b - *(int *)a);
}

int main() 
{
    FILE *file;
    int sales[MAXEMP];
    int asc[MAXEMP];
    int desc[MAXEMP];
    int count = 0;

    file = fopen("C:\\Users\\garci\\Downloads\\sales.txt", "r"); //ruta de acceso de mis descargas, copiar ruta de acceso para sales.txt y usar '\\' de preferencia
    if (file == NULL) 
	{
        printf("Error opening file.\n");
        return 1;
    }

    // lee archivo
    while (fscanf(file, "%d", &sales[count]) == 1 && count < MAXEMP) 
	{
        count++;
    }
    fclose(file);

    // copia los datos y los acomoda en ascendente y descendente como matriz o array
    for (int i = 0; i < count; i++) 
	{
        asc[i] = sales[i];
        desc[i] = sales[i];
    }

    // sortea los arrays
    qsort(asc, count, sizeof(int), compareAsc);
    qsort(desc, count, sizeof(int), compareDesc);

    // imprime con formato de tabla
    printf("%-12s %-12s %-12s\n", "Original", "Ascending", "Descending");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < count; i++) 
	{
        printf("%-12d %-12d %-12d\n", sales[i], asc[i], desc[i]);
    }

    return 0;
}
