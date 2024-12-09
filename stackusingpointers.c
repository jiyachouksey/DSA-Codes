#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* top = NULL;


void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Stack Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed into stack.\n", value);
}


void pop() {
    if (!top)
        printf("Stack Underflow\n");
    else {
        struct Node* temp = top;
        printf("%d popped from stack.\n", temp->data);
        top = top->next;
        free(temp);
    }
}


void display() {
    if (!top)
        printf("Stack is empty.\n");
    else {
        struct Node* temp = top;
        printf("Stack elements: ");
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main() {
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}
