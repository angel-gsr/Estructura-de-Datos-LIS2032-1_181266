#include <cstdio>
#include <cstdlib>

int main() {
    int rows = 3, cols = 4;

    // 1. Reserva de memoria para la matriz
    int **M = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        M[i] = (int*)malloc(cols * sizeof(int));
    }

    // 2. Llenar la matriz con valores consecutivos
    int value = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            *(*(M + i) + j) = value++;  // equivalente a M[i][j]
        }
    }

    // 3. Imprimir la matriz usando punteros
    printf("Matriz:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", *(*(M + i) + j));
        }
        printf("\n");
    }

    // 4. Liberar memoria
    for (int i = 0; i < rows; i++) {
        free(M[i]);
    }
    free(M);

    return 0;
}

