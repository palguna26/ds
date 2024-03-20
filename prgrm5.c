#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the circular doubly linked list
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the circular doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    do {
        printf("%d ", current->data);
        current = current->next;
    } while (current != head);

    printf("\n");
}

// Function to insert a node in order
struct Node* insertByOrder(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        newNode->prev = newNode;
        return newNode;
    }

    struct Node* current = head;
    while (current->next != head && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;

    if (value < head->data) {
        // Adjust head if the new node is inserted before the current head
        head = newNode;
    }

    return head;
}

// Function to delete a node by position
struct Node* deleteByPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Node* current = head;
    struct Node* temp;

    if (position == 1) {
        // Delete the first node
        temp = current;
        current->prev->next = current->next;
        current->next->prev = current->prev;
        head = current->next;

        free(temp);
    } else {
        // Delete a node other than the first one
        for (int i = 1; i < position - 1; i++) {
            current = current->next;
        }

        if (current->next == head) {
            printf("Invalid position. Cannot delete beyond the end.\n");
            return head;
        }

        temp = current->next;
        current->next = temp->next;
        temp->next->prev = current;

        free(temp);
    }

    return head;
}

// Function to delete a node by key
struct Node* deleteByKey(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Node* current = head;
    struct Node* temp;

    do {
        if (current->data == key) {
            // Delete the node
            temp = current;

            if (current == head) {
                head = current->next;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            free(temp);
            return head;
        }

        current = current->next;
    } while (current != head);

    printf("Item %d not found in the list.\n", key);

    return head;
}

// Function to search for an item by position
void searchByPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* current = head;
    int currentPosition = 1;

    do {
        if (currentPosition == position) {
            printf("Item at position %d: %d\n", position, current->data);
            return;
        }

        current = current->next;
        currentPosition++;
    } while (current != head);

    printf("Invalid position. Please enter a valid position.\n");
}

int main() {
    struct Node* head = NULL;
    int choice, value, position, key;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Insert by order\n");
        printf("2. Delete by position\n");
        printf("3. Delete by key\n");
        printf("4. Search by position\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertByOrder(head, value);
                displayList(head);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteByPosition(head, position);
                displayList(head);
                break;
            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                head = deleteByKey(head, key);
                displayList(head);
                break;
            case 4:
                printf("Enter position to search: ");
                scanf("%d", &position);
                searchByPosition(head, position);
                break;
            case 5:
                displayList(head);
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    // Free allocated memory
    struct Node* current = head;
    struct Node* next;
    if (current != NULL) {
        do {
            next = current->next;
            free(current);
            current = next;
        } while (current != head);
    }

    return 0;
}
