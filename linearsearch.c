#include <stdio.h>

// Non-Recursive Linear Search
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key)
            return i;
    }
    return -1;
}

// Recursive Linear Search
int linearSearchRec(int arr[], int n, int key, int index) {
    if (index >= n)
        return -1;
    if (arr[index] == key)
        return index;
    return linearSearchRec(arr, n, key, index + 1);
}

// Main Function
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int result = linearSearch(arr, n, key);
    if (result != -1)
        printf("Non-Recursive: Element found at index %d\n", result);
    else
        printf("Non-Recursive: Element not found\n");

    result = linearSearchRec(arr, n, key, 0);
    if (result != -1)
        printf("Recursive: Element found at index %d\n", result);
    else
        printf("Recursive: Element not found\n");

    return 0;
}
