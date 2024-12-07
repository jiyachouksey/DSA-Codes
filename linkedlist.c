#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
struct Node* createNode(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertAtBeginning(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertAtEnd(struct Node** head, int data){
    struct Node* newNode = createNode(data);
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while(temp->next !=NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void deleteNode(struct Node**head, int key){
    struct Node* temp = *head;
    struct Node* prev = NULL;
    if(temp != NULL && temp->data == key){
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    prev->next = temp->next;
    free(temp);
}
void traverseList(struct Node* head){
    struct Node* temp = head;
    while (temp != NULL){
        printf("%d ->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main(){
    struct Node* head = NULL;
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    printf("Linked list after creation:");
    traverseList(head);

    insertAtBeginning(&head, 5);
    printf("After inserting 5 at the beginning:");
    traverseList(head);
    
    insertAtEnd(&head, 40);
    printf("fter inserting 40 at the end:");
    traverseList(head);

    deleteNode(&head, 20);
    printf("After deleting 20:");
    traverseList(head);

    return 0;
}


