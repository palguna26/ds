#include <stdio.h>
#include <stdlib.h>

// Define a node structure for the circular singly linked list
struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to display the circular singly linked list
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

// Function to insert a node at the front
struct Node* insertFront(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }

    newNode->next = head;
    last->next = newNode;

    return newNode;
}

// Function to insert a node at the rear
struct Node* insertRear(struct Node* head, int value) {
    struct Node* newNode = createNode(value);

    if (head == NULL) {
        newNode->next = newNode;
        return newNode;
    }

    newNode->next = head;
    struct Node* last = head;
    while (last->next != head) {
        last = last->next;
    }
    last->next = newNode;

    return head;
}

// Function to delete a node with the given key
struct Node* deleteByKey(struct Node* head, int key) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return NULL;
    }

    struct Node* current = head;
    struct Node* temp;

    if (current->data == key) {
        // Delete the first node
        if (current->next == head) {
            // Only one node in the list
            free(current);
            return NULL;
        }

        struct Node* last = head;
        while (last->next != head) {
            last = last->next;
        }

        head = current->next;
        last->next = head;
        free(current);
    } else {
        // Delete a node other than the first one
        while (current->next != head && current->next->data != key) {
            current = current->next;
        }

        if (current->next == head) {
            printf("Item %d not found in the list.\n", key);
            return head;
        }

        temp = current->next;
        current->next = temp->next;
        free(temp);
    }

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
        printf("1. Insert front\n");
        printf("2. Insert rear\n");
        printf("3. Delete by key\n");
        printf("4. Search by position\n");
        printf("5. Display the list\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at front: ");
                scanf("%d", &value);
                head = insertFront(head, value);
                displayList(head);
                break;
            case 2:
                printf("Enter value to insert at rear: ");
                scanf("%d", &value);
                head = insertRear(head, value);
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
