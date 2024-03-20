#include <stdio.h>
#include <stdlib.h>

// Function to display the array contents
void displayArray(int *arr, int size) {
    printf("Array contents: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element in order
int* insertByOrder(int *arr, int *size, int element) {
    (*size)++;
    arr = realloc(arr, (*size) * sizeof(int));

    int i = *size - 1;
    while (i > 0 && arr[i - 1] > element) {
        arr[i] = arr[i - 1];
        i--;
    }

    arr[i] = element;

    return arr;
}

// Function to delete an element by position
int* deleteByPosition(int *arr, int *size, int position) {
    if (position >= 0 && position < *size) {
        for (int i = position; i < *size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        (*size)--;
        arr = realloc(arr, (*size) * sizeof(int));
        displayArray(arr, *size);
    } else {
        printf("Invalid position. Please enter a valid position.\n");
    }

    return arr;
}

// Function to search for an element by key
void searchByKey(int *arr, int size, int key) {
    int found = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            printf("Element %d found at position %d.\n", key, i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Element %d not found in the array.\n", key);
    }
}

// Function to reverse the array contents
void reverseContents(int *arr, int size) {
    for (int i = 0, j = size - 1; i < j; i++, j--) {
        // Swap elements
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {
    int *arr = NULL;
    int size = 0;
    int choice, position, element, key;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Insert by order\n");
        printf("2. Delete by position\n");
        printf("3. Search by key\n");
        printf("4. Reverse the contents\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &element);
                arr = insertByOrder(arr, &size, element);
                displayArray(arr, size);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                arr = deleteByPosition(arr, &size, position);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                searchByKey(arr, size, key);
                break;
            case 4:
                reverseContents(arr, size);
                displayArray(arr, size);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    // Free allocated memory
    free(arr);

    return 0;
}
