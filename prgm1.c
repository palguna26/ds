#include <stdio.h>
#include <stdlib.h>

// Define the structure
struct Student {
    char Name[50];
    int Reg_no;
    float marks[3];
    float average_marks;
};

// Function to read information of N students
void readStudents(struct Student *students, int N) {
    for (int i = 0; i < N; i++) {
        printf("Enter details for Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", students[i].Name);
        printf("Registration Number: ");
        scanf("%d", &students[i].Reg_no);

        printf("Enter marks for 3 tests:\n");
        for (int j = 0; j < 3; j++) {
            printf("Test %d: ", j + 1);
            scanf("%f", &students[i].marks[j]);
        }
    }
}

// Function to display student's information
void displayStudents(struct Student *students, int N) {
    printf("\nStudent Information:\n");
    for (int i = 0; i < N; i++) {
        printf("Student %d:\n", i + 1);
        printf("Name: %s\n", students[i].Name);
        printf("Registration Number: %d\n", students[i].Reg_no);
        printf("Test Marks: %.2f, %.2f, %.2f\n", students[i].marks[0], students[i].marks[1], students[i].marks[2]);
        printf("Average Marks: %.2f\n", students[i].average_marks);
        printf("\n");
    }
}

// Function to calculate the average of best two test marks for each student
void calculateAverage(struct Student *students, int N) {
    for (int i = 0; i < N; i++) {
        // Find the two highest test marks
        float highest1 = 0, highest2 = 0;
        for (int j = 0; j < 3; j++) {
            if (students[i].marks[j] > highest1) {
                highest2 = highest1;
                highest1 = students[i].marks[j];
            } else if (students[i].marks[j] > highest2) {
                highest2 = students[i].marks[j];
            }
        }

        // Calculate average of best two test marks
        students[i].average_marks = (highest1 + highest2) / 2;
    }
}

int main() {
    int N;
    printf("Enter the number of students: ");
    scanf("%d", &N);

    // Dynamically allocate memory for N students
    struct Student *students = (struct Student *)malloc(N * sizeof(struct Student));

    // Check if memory allocation was successful
    if (students == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        return 1;
    }

    int choice;

    do {
        // Display menu
        printf("\nMenu:\n");
        printf("1. Read student information\n");
        printf("2. Display student information\n");
        printf("3. Calculate average of best two test marks\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                readStudents(students, N);
                break;
            case 2:
                displayStudents(students, N);
                break;
            case 3:
                calculateAverage(students, N);
                printf("Average calculated successfully.\n");
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Free allocated memory
    free(students);

    return 0;
}
