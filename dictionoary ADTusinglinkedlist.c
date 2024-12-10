#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char key[50];
    char value[50];
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(char key[], char value[]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->key, key);
    strcpy(newNode->value, value);
    newNode->next = NULL;
    return newNode;
}

// Function to insert a key-value pair
void insert(struct Node** head, char key[], char value[]) {
    struct Node* newNode = createNode(key, value);
    newNode->next = *head;
    *head = newNode;
    printf("Inserted: (%s, %s)\n", key, value);
}

// Function to search for a key
void search(struct Node* head, char key[]) {
    struct Node* temp = head;
    while (temp != NULL) {
        if (strcmp(temp->key, key) == 0) {
            printf("Found: Key = %s, Value = %s\n", temp->key, temp->value);
            return;
        }
        temp = temp->next;
    }
    printf("Key '%s' not found.\n", key);
}

// Function to delete a key
void deleteKey(struct Node** head, char key[]) {
    struct Node* temp = *head, *prev = NULL;

    while (temp != NULL && strcmp(temp->key, key) != 0) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Key '%s' not found.\n", key);
        return;
    }

    if (prev == NULL) {
        *head = temp->next;  // Key is in the first node
    } else {
        prev->next = temp->next;
    }

    printf("Deleted: Key = %s\n", key);
    free(temp);
}

// Function to display all key-value pairs
void display(struct Node* head) {
    if (head == NULL) {
        printf("Dictionary is empty.\n");
        return;
    }

    printf("Dictionary Contents:\n");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("Key: %s, Value: %s\n", temp->key, temp->value);
        temp = temp->next;
    }
}

// Main function
int main() {
    struct Node* dictionary = NULL;
    int choice;
    char key[50], value[50];

    do {
        printf("\nDictionary Operations:\n");
        printf("1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key: ");
                scanf("%s", key);
                printf("Enter value: ");
                scanf("%s", value);
                insert(&dictionary, key, value);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%s", key);
                search(dictionary, key);
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%s", key);
                deleteKey(&dictionary, key);
                break;

            case 4:
                display(dictionary);
                break;

            case 5:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
