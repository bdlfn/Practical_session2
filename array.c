#include <stdio.h>

#define MAX_SIZE 100 // Maximum size of the array list

int search(int arr[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main() {
    int arr[MAX_SIZE] = {2, 5, 9, 12, 15}; // Example array list
    int size = 5; // Size of the array list
    int key = 9; // Value to search for
    
    int index = search(arr, size, key);
    if (index != -1) {
        printf("Element %d found at index %d\n", key, index);
    } else {
        printf("Element %d not found in the array list\n", key);
    }

    return 0;
}
