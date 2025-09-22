/*
#include <stdlib.h>
#include <stdio.h>

int main
{
	void enqueue(int val)
	{
		queue[rear]=val;
		numCurrentElements++;
		rear++;
		
		if(rear==QUEUESIZE)
		{
			rear=0;
		}
	}
	int dequeue()
	{
		val=queue[front];
		numCurrentElements--;
		front++;
		
		if(front==QUEUESIZE)
		{
			rear=0;
		}
		
		return val;
	}
	
	void printQueue()
	{
		printf("\n Queue;");
		
		if(rear<=front)
		{
			for(int i=front;i<QUEUESIZE;i++)
			{
				printf(" %d",queue[i]);
			}
			for(int i=0;i<rear;i++)
			{
				printf(" %d",queue[i]);
			}
		}
		else
		{
			for(int i=front;i<rear;i++)
			{
				printf(" %d",queue[i]);	
			}
		}
		printf("\n");
	}
	return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Function to check if queue is full
int isFull() {
    return (rear + 1) % SIZE == front;
}

// Function to check if queue is empty
int isEmpty() {
    return front == -1;
}

// Enqueue function
void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full. Cannot enqueue %d\n", value);
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    queue[rear] = value;
    printf("Enqueued: %d\n", value);
}

// Dequeue function
void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    int value = queue[front];
    if (front == rear) {
        // Queue becomes empty
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    printf("Dequeued: %d\n", value);
}

// Display queue content
void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue content: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Exit\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter an integer to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                displayQueue();
                break;
            case 2:
                dequeue();
                displayQueue();
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

