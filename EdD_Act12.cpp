#include <stdio.h>
#include <stdlib.h>

// Definición del nodo
typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

// Definición de la cola (Queue)
typedef struct Queue 
{
    Node* front;
    Node* rear;
} Queue;

// Inicializa la cola
void initQueue(Queue* q) 
{
    q->front = NULL;
    q->rear = NULL;
}

// Verifica si la cola está vacía
int isEmpty(Queue* q) 
{
    return (q->front == NULL);
}

// Encolar (insertar al final)
void enqueue(Queue* q, int value) 
{
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) 
	{
        printf("Error: no se pudo asignar memoria.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) 
	{
        q->front = q->rear = newNode;
    } 
	else 
	{
        q->rear->next = newNode;
        q->rear = newNode;
    }
    printf("%d encolado en la cola.\n", value);
}

// Desencolar (sacar del frente)
void dequeue(Queue* q) 
{
    if (isEmpty(q)) 
	{
        printf("La cola esta vacia. No se puede desencolar.\n");
        return;
    }
    Node* temp = q->front;
    printf("%d desencolado de la cola.\n", temp->data);
    q->front = q->front->next;

    if (q->front == NULL) 
	{  // si la cola queda vacía
        q->rear = NULL;
    }
    free(temp);
}

// Ver el elemento del frente
void peek(Queue* q) 
{
    if (isEmpty(q)) 
	{
        printf("La cola esta vacia.\n");
    } else {
        printf("Elemento al frente: %d\n", q->front->data);
    }
}

// Mostrar todos los elementos
void display(Queue* q) 
{
    if (isEmpty(q)) 
	{
        printf("La cola esta vacia.\n");
        return;
    }
    printf("Elementos de la cola: ");
    Node* temp = q->front;
    while (temp != NULL) 
	{
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Liberar memoria de toda la cola
void freeQueue(Queue* q) 
{
    while (!isEmpty(q)) 
	{
        dequeue(q);
    }
}

// Programa de prueba
int main() 
{
    Queue q;
    initQueue(&q);
    int choice, value;

    do 
	{
        printf("\n--- Menu de Cola (Queue) ---\n");
        printf("1. Encolar\n");
        printf("2. Desencolar\n");
        printf("3. Peek (ver frente)\n");
        printf("4. Mostrar\n");
        printf("5. Salir\n");
        printf("Elige una opcion: ");
        scanf("%d", &choice);

        switch (choice) 
		{
        case 1:
            printf("Ingrese valor a encolar: ");
            scanf("%d", &value);
            enqueue(&q, value);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            peek(&q);
            break;
        case 4:
            display(&q);
            break;
        case 5:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opcion invalida.\n");
        }
    } 
	while (choice != 5);

    freeQueue(&q);
    return 0;
}

