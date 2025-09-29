#include <stdio.h>
#include <stdlib.h>

// estructura del nodo
struct Node 
{
    int data;
    struct Node* next;
};

// crear nodo 1
struct Node* createNode(int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// mostrar nodo 2
void displayList(struct Node* head) 
{
    struct Node* current = head;
    printf("Linked List: ");
    while (current != NULL) 
	{
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// insertar en el inicio 3
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// inserta nodo en ppsicion especifica 4
struct Node* insertAtPosition(struct Node* head, int data, int position) {
    if (position < 1) 
	{
        printf("Invalid position!\n");
        return head;
    }
    
    if (position == 1) 
	{
        return insertAtBeginning(head, data);
    }
    
    struct Node* newNode = createNode(data);
    struct Node* current = head;
    
    // intercalar con la posicion anterior 5
    for (int i = 1; i < position - 1 && current != NULL; i++) 
	{
        current = current->next;
    }
    
    if (current == NULL) 
	{
        printf("Position out of range!\n");
        free(newNode);
        return head;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

// insertar nodo en el ultimo 6
struct Node* insertAtEnd(struct Node* head, int data) 
{
    struct Node* newNode = createNode(data);
    
    if (head == NULL) {
        return newNode;
    }
    
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    
    current->next = newNode;
    return head;
}

// eliminar nodo del inicio 7
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is already empty!\n");
        return NULL;
    }
    
    struct Node* temp = head;
    head = head->next;
    free(temp);
    printf("Node deleted from beginning.\n");
    return head;
}

// eliminar nodo del final 8
struct Node* deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is already empty!\n");
        return NULL;
    }
    
    if (head->next == NULL) {
        // Only one node
        free(head);
        printf("Node deleted from end.\n");
        return NULL;
    }
    
    struct Node* current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }
    
    free(current->next);
    current->next = NULL;
    printf("Node deleted from end.\n");
    return head;
}

// eliminar nodo en la posicion n 9
struct Node* deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty!\n");
        return NULL;
    }
    
    if (position < 1) {
        printf("Invalid position!\n");
        return head;
    }
    
    if (position == 1) {
        return deleteAtBeginning(head);
    }
    
    struct Node* current = head;
    
    // intercalar con la posicion anterior
    for (int i = 1; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }
    
    if (current == NULL || current->next == NULL) {
        printf("Position out of range!\n");
        return head;
    }
    
    struct Node* temp = current->next;
    current->next = temp->next;
    free(temp);
    printf("Node deleted from position %d.\n", position);
    return head;
}

// liberar la lista completa
void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

// funcion main///////////////////////////////7
int main() {
    struct Node* head = NULL;
    int choice, data, position;
    
    printf("Single Linked List Implementation\n");
    printf("================================\n");
    
    do {
        printf("\nMenu:\n");
        printf("1. Display List\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert at End\n");
        printf("4. Insert at Position\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete from Position\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                displayList(head);
                break;
                
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
                
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
                
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtPosition(head, data, position);
                break;
                
            case 5:
                head = deleteAtBeginning(head);
                break;
                
            case 6:
                head = deleteAtEnd(head);
                break;
                
            case 7:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteAtPosition(head, position);
                break;
                
            case 8:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 8);
    
    // libera
    freeList(head);
    
    return 0;
}
