#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#define MAX_NAME_LEN 50
#define MAX_ID_LEN 10
#define MAX_SUBJECTS 5

// Function to display student menu
void studentMenu(int studentID) {
    int choice;
    
    while (1) {
        printf("\n====================\n");
        printf(" Student Dashboard \n");
        printf("====================\n");
        printf("1. View Grades\n");
        printf("2. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewGrades(studentID);
                break;
            case 2:
                printf("Logging out...\n");
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Function to view student grades
void viewGrades(int studentID) {
    char line[200];
    FILE *file = fopen("data/students.csv", "r");

    if (!file) {
        printf("Error opening student database!\n");
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        int sID;
        char name[MAX_NAME_LEN], admNo[MAX_ID_LEN];
        int english, kiswahili, science, maths, socialStudies;

        // Read data from CSV
        sscanf(line, "%d,%49[^,],%9[^,],%d,%d,%d,%d,%d", 
               &sID, name, admNo, &english, &kiswahili, &science, &maths, &socialStudies);

        // Check if student ID matches
        if (sID == studentID) {
            printf("\n===== Student Grades =====\n");
            printf("Name: %s\n", name);
            printf("Admission No: %s\n", admNo);
            printf("English: %d\n", english);
            printf("Kiswahili: %d\n", kiswahili);
            printf("Science: %d\n", science);
            printf("Mathematics: %d\n", maths);
            printf("Social Studies: %d\n", socialStudies);
            fclose(file);
            return;
        }
    }

    printf("Student record not found!\n");
    fclose(file);
}
