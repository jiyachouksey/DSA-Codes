#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Head pointer
struct Node* head = NULL;

// Function to create a circular linked list
void create(int data[], int n) {
    struct Node *newNode, *temp;
    for (int i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data[i];
        if (head == NULL) {
            head = newNode;
            head->next = head;
        } else {
            temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }
}

// Function to insert at the beginning
void insertAtBeginning(int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
}

// Function to insert at the end
void insertAtEnd(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        struct Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

// Function to delete a node
void deleteNode(int key) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *temp = head, *prev;

    // If the node to be deleted is the head
    if (head->data == key) {
        while (temp->next != head)
            temp = temp->next;

        if (head == head->next) {
            free(head);
            head = NULL;
        } else {
            temp->next = head->next;
            free(head);
            head = temp->next;
        }
        return;
    }

    // Searching for the node to delete
    prev = NULL;
    while (temp->next != head && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp->data == key) {
        prev->next = temp->next;
        free(temp);
    } else {
        printf("Node with value %d not found.\n", key);
    }
}

// Function to traverse and display the list
void traverse() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }
    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Main Function
int main() {
    int data[] = {10, 20, 30, 40};
    create(data, 4);

    printf("Initial List:\n");
    traverse();

    insertAtBeginning(5);
    printf("\nAfter Inserting 5 at the Beginning:\n");
    traverse();

    insertAtEnd(50);
    printf("\nAfter Inserting 50 at the End:\n");
    traverse();

    deleteNode(30);
    printf("\nAfter Deleting 30:\n");
    traverse();

    deleteNode(5);
    printf("\nAfter Deleting 5 (Head):\n");
    traverse();

    return 0;
}
