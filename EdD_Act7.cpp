#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
// funciones  para imprimir total
float totalSale(float sales[], int n) 
{
    float total=0.0; //con 0.0 para no generar error
    for (int i=0;i<n;i++) 
	{
        total+= sales[i]; //autosuma
    }
    return total; //regresa la suma en la variable total
}

//venta maxima 
float maxSale(float sales[], int n) 
{
    float max = sales[0];
    for (int i = 1; i < n; i++) 
	{
        if (sales[i] > max) 
		{
            max = sales[i];
        }
    }
    return max; //regresa el  ultimo máximo a la varianle max
}

int main() 
{
    FILE *archivo;
    archivo = fopen("C:/Users/garci/Downloads/sales.txt", "r");
    if (archivo == NULL) 
	{
        perror("Error al abrir el archivo");
        return 1;
    }

    int count = 0;
    float temp;

    // Primera pasada: contar cuántas líneas/valores hay
    while (fscanf(archivo, "%f", &temp) == 1) 
	{
        count++;
    }

    if (count == 0) 
	{
        printf("El archivo esta vacío.\n");
        fclose(archivo);
        return 1;
    }

    //////////////////////////////// memoria dinamica
    float *sales=(float*)malloc(count*sizeof(float)); //en vez de int
    if (sales == NULL) 
	{
        perror("Error al reservar memoria");
        fclose(archivo);
        return 1; //en caso de error arrojar 1
    }

    // Volver al inicio del archivo para leer los datos
    rewind(archivo);

    // Segunda pasada: leer valores en el arreglo
    for (int i=0;i<count;i++) {
        fscanf(archivo, "%f", &sales[i]);
    }
    //////////////////
    fclose(archivo);
	/////////////////
    
    //llamado de funciones definidas fuera del programa
    float total=totalSale(sales, count); //nuestros parametros de entrada son float sales, y count que son int 
    float max=maxSale(sales, count);
    
    printf("Numero de ventas: %d\n", count);
    printf("Total de ventas: %.2f\n", total);
    printf("Venta máxima: %.2f\n", max);

    //liberar memoria
    free(sales);

    return 0;
}


/*r opens a fie for reading
w creates a file for writing and writes over all previous content 
a 

stdin reads input from keyboard
stdout send output to the screen
stderr prints error to an eror device

int getchar()
int fgetc(FILE*archivo)
int putchar(int c)
int fputc(int
*/
