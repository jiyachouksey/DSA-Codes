#include <stdio.h>

// Non-Recursive Binary Search
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

// Recursive Binary Search
int binarySearchRec(int arr[], int left, int right, int key) {
    if (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
            return mid;
        if (arr[mid] < key)
            return binarySearchRec(arr, mid + 1, right, key);
        else
            return binarySearchRec(arr, left, mid - 1, key);
    }
    return -1;
}

// Main Function
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 30;

    int result = binarySearch(arr, n, key);
    if (result != -1)
        printf("Non-Recursive: Element found at index %d\n", result);
    else
        printf("Non-Recursive: Element not found\n");

    result = binarySearchRec(arr, 0, n - 1, key);
    if (result != -1)
        printf("Recursive: Element found at index %d\n", result);
    else
        printf("Recursive: Element not found\n");

    return 0;
}
