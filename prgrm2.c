#include <stdio.h>

// Define the structure
struct Time {
    int Hour;
    int Minute;
    int Second;
};

// Function to read time
void readTime(struct Time *t) {
    printf("Enter time (HH MM SS): ");
    scanf("%d %d %d", &t->Hour, &t->Minute, &t->Second);
}

// Function to display time
void displayTime(struct Time *t) {
    printf("Time: %02d:%02d:%02d\n", t->Hour, t->Minute, t->Second);
}

// Function to update time by one second
struct Time update(struct Time *t) {
    t->Second++;
    if (t->Second == 60) {
        t->Second = 0;
        t->Minute++;
        if (t->Minute == 60) {
            t->Minute = 0;
            t->Hour++;
            if (t->Hour == 24) {
                // Reset time to zero if hour becomes 24
                t->Hour = 0;
            }
        }
    }
    return *t;
}

// Function to add two time variables
struct Time add(struct Time *t1, struct Time *t2) {
    struct Time result;
    result.Second = (t1->Second + t2->Second) % 60;
    result.Minute = ((t1->Minute + t2->Minute) + (t1->Second + t2->Second) / 60) % 60;
    result.Hour = (t1->Hour + t2->Hour) + ((t1->Minute + t2->Minute) + (t1->Second + t2->Second) / 60) / 60;

    // Normalize the resultant time
    update(&result);

    return result;
}

int main() {
    struct Time time1, time2, result;
    int choice;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Read time\n");
        printf("2. Display time\n");
        printf("3. Update time\n");
        printf("4. Add two time variables\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readTime(&time1);
                break;
            case 2:
                displayTime(&time1);
                break;
            case 3:
                update(&time1);
                printf("Time updated successfully.\n");
                break;
            case 4:
                readTime(&time1);
                readTime(&time2);
                result = add(&time1, &time2);
                printf("Resultant time after addition: ");
                displayTime(&result);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 5);

    return 0;
}
