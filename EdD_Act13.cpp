#include <stdio.h>
#include <stdlib.h>

typedef struct Node 
{
    int data;
    struct Node* next;
} Node;

typedef struct CircularLinkedList 
{
    Node* head;
    int size;
} CircularLinkedList;

// Inicializar lista
void initList(CircularLinkedList* list) 
{
    list->head = NULL;
    list->size = 0;
}

// Verifica si está vacía
int isEmpty(CircularLinkedList* list) 
{
    return list->size == 0;
}

// Retorna tamaño
int getSize(CircularLinkedList* list) 
{
    return list->size;
}

// Obtener cabeza
Node* getHead(CircularLinkedList* list) 
{
    return list->head;
}

// Obtener cola
Node* getTail(CircularLinkedList* list) 
{
    if (isEmpty(list)) return NULL;
    Node* temp = list->head;
    while (temp->next != list->head) 
	{
        temp = temp->next;
    }
    return temp;
}

// Agregar al frente
void addFront(CircularLinkedList* list, int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (isEmpty(list)) 
	{
        newNode->next = newNode;
        list->head = newNode;
    } 
	else 
	{
        Node* tail = getTail(list);
        newNode->next = list->head;
        list->head = newNode;
        tail->next = list->head;
    }
    list->size++;
}

// Agregar al final
void addEnd(CircularLinkedList* list, int value) 
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if (isEmpty(list)) 
	{
        newNode->next = newNode;
        list->head = newNode;
    } 
	else 
	{
        Node* tail = getTail(list);
        newNode->next = list->head;
        tail->next = newNode;
    }
    list->size++;
}

// Agregar en posición
void addAtPosition(CircularLinkedList* list, int value, int pos) 
{
    if (pos < 0 || pos > list->size) 
	{
        printf("Posición inválida.\n");
        return;
    }
    if (pos == 0) 
	{
        addFront(list, value);
    } else if (pos == list->size) 
	{
        addEnd(list, value);
    } 
	else 
	{
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = value;
        Node* temp = list->head;
        for (int i = 0; i < pos - 1; i++) 
		{
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        list->size++;
    }
}

// Eliminar al frente
void removeFront(CircularLinkedList* list) 
{
    if (isEmpty(list)) 
	{
        printf("Lista vacía.\n");
        return;
    }
    Node* temp = list->head;
    if (list->size == 1) 
	{
        list->head = NULL;
    } 
	else 
	{
        Node* tail = getTail(list);
        list->head = list->head->next;
        tail->next = list->head;
    }
    printf("Eliminado: %d\n", temp->data);
    free(temp);
    list->size--;
}

// Eliminar al final
void removeEnd(CircularLinkedList* list) 
{
    if (isEmpty(list)) 
	{
        printf("Lista vacía.\n");
        return;
    }
    if (list->size == 1) 
	{
        removeFront(list);
        return;
    }
    Node* temp = list->head;
    while (temp->next->next != list->head) 
	{
        temp = temp->next;
    }
    Node* last = temp->next;
    temp->next = list->head;
    printf("Eliminado: %d\n", last->data);
    free(last);
    list->size--;
}

// Eliminar en posición
void removeAtPosition(CircularLinkedList* list, int pos) 
{
    if (isEmpty(list) || pos < 0 || pos >= list->size) 
	{
        printf("Posición inválida o lista vacía.\n");
        return;
    }
    if (pos == 0) 
	{
        removeFront(list);
    } else if (pos == list->size - 1) 
	{
        removeEnd(list);
    } else {
        Node* temp = list->head;
        for (int i = 0; i < pos - 1; i++) 
		{
            temp = temp->next;
        }
        Node* delNode = temp->next;
        temp->next = delNode->next;
        printf("Eliminado: %d\n", delNode->data);
        free(delNode);
        list->size--;
    }
}

// Buscar un valor
int search(CircularLinkedList* list, int value) 
{
    if (isEmpty(list)) return -1;
    Node* temp = list->head;
    int index = 0;
    do 
	{
        if (temp->data == value) return index;
        temp = temp->next;
        index++;
    } 
	while (temp != list->head);
    return -1;
}

// Recorrer lista
void traverse(CircularLinkedList* list) 
{
    if (isEmpty(list)) 
	{
        printf("Lista vacía.\n");
        return;
    }
    Node* temp = list->head;
    printf("Recorrido: ");
    do 
	{
        printf("%d ", temp->data);
        temp = temp->next;
    } 
	while (temp != list->head);
    printf("\n");
}

// Limpiar lista
void clear(CircularLinkedList* list) 
{
    while (!isEmpty(list)) 
	{
        removeFront(list);
    }
}

// Mostrar (Display)
void display(CircularLinkedList* list)
{
    traverse(list);
}

//////////////////////
// Programa de prueba
//////////////////////
int main() 
{
    CircularLinkedList list;
    initList(&list);
    int choice, value, pos;

    do 
	{
        printf("\n--- Menu Lista Circular ---\n");
        printf("1. Agregar al frente\n");
        printf("2. Agregar al final\n");
        printf("3. Agregar en posición\n");
        printf("4. Eliminar al frente\n");
        printf("5. Eliminar al final\n");
        printf("6. Eliminar en posición\n");
        printf("7. Buscar valor\n");
        printf("8. Recorrer\n");
        printf("9. Mostrar tamaño\n");
        printf("10. ¿Está vacía?\n");
        printf("11. Limpiar lista\n");
        printf("12. Mostrar (Display)\n");
        printf("13. Obtener cabeza\n");
        printf("14. Obtener cola\n");
        printf("15. Salir\n");
        printf("Elige opción: ");
        scanf("%d", &choice);

        switch (choice) 
		{
        case 1:
            printf("Valor: ");
            scanf("%d", &value);
            addFront(&list, value);
            break;
        case 2:
            printf("Valor: ");
            scanf("%d", &value);
            addEnd(&list, value);
            break;
        case 3:
            printf("Valor y posición: ");
            scanf("%d %d", &value, &pos);
            addAtPosition(&list, value, pos);
            break;
        case 4:
            removeFront(&list);
            break;
        case 5:
            removeEnd(&list);
            break;
        case 6:
            printf("Posición: ");
            scanf("%d", &pos);
            removeAtPosition(&list, pos);
            break;
        case 7:
            printf("Valor a buscar: ");
            scanf("%d", &value);
            pos = search(&list, value);
            if (pos != -1) printf("Encontrado en posición %d\n", pos);
            else printf("No encontrado.\n");
            break;
        case 8:
            traverse(&list);
            break;
        case 9:
            printf("Tamaño: %d\n", getSize(&list));
            break;
        case 10:
            printf("¿Vacía?: %s\n", isEmpty(&list) ? "Sí" : "No");
            break;
        case 11:
            clear(&list);
            break;
        case 12:
            display(&list);
            break;
        case 13:
            if (getHead(&list)) printf("Cabeza: %d\n", getHead(&list)->data);
            else printf("Lista vacía.\n");
            break;
        case 14:
            if (getTail(&list)) printf("Cola: %d\n", getTail(&list)->data);
            else printf("Lista vacía.\n");
            break;
        case 15:
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción inválida.\n");
        }
    } 
	while (choice != 15);

    clear(&list);
    return 0;
}

