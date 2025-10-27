/////////////////////////// indices
/*
#include <stdio.h>
#define MAX_ELEMENTS 10

typedef struct {
    char nodes[MAX_ELEMENTS];
    int numElements;
} BinaryTree;

int main() {
    BinaryTree tree = {
        .nodes = {'G', 'D', 'I', 'B', 'F', 'H', 'J', 'A', 'C', 'E'},
        .numElements = 10
    };

    // Mostrar el árbol como arreglo
    printf("Arbol binario representado en arreglo:\n");
    for (int i = 0; i < tree.numElements; i++) {
        printf("Indice %d -> %c\n", i, tree.nodes[i]);
    }

    return 0;
}
*/
////////////////////////////////// añadiendo nodos 

#include <stdio.h>
#define MAX_ELEMENTS 11

typedef struct {
    char nodes[MAX_ELEMENTS];
    int numElements;
} BinaryTree;

int main() {
    BinaryTree tree = {
        .nodes = {'G', 'D', 'I', 'B', 'F', 'H', 'J', 'A', 'C', 'E', 'K'}, //nodo k
        .numElements = 11
    };

    printf("Arbol binario lleno representado en arreglo:\n");
    for (int i = 0; i < tree.numElements; i++) {
        printf("Indice %d -> %c\n", i, tree.nodes[i]);
    }

    return 0;
}

