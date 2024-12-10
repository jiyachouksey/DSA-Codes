#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Front and rear pointers
struct Node *front = NULL, *rear = NULL;

// Function to enqueue an element
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    if (rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    printf("%d enqueued into queue.\n", value);
}

// Function to dequeue an element
void dequeue() {
    if (front == NULL)
        printf("Queue Underflow\n");
    else {
        struct Node* temp = front;
        printf("%d dequeued from queue.\n", temp->data);
        front = front->next;
        if (front == NULL)
            rear = NULL;
        free(temp);
    }
}

// Function to display the queue
void display() {
    if (front == NULL)
        printf("Queue is empty.\n");
    else {
        struct Node* temp = front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Main function
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    dequeue();
    display();
    return 0;
}
