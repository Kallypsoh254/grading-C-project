#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "admin.h"

#define MAX_NAME_LEN 50
#define MAX_ID_LEN 10
#define MAX_LINE 200
#define MAX_SUBJECTS 5

// Function to display admin menu
void adminMenu() {
    int choice;

    while (1) {
        printf("\n====================\n");
        printf(" Admin Dashboard \n");
        printf("====================\n");
        printf("1. View All Student Grades\n");
        printf("2. Modify Student Grades\n");
        printf("3. Logout\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                viewAllGrades();
                break;
            case 2:
                modifyStudentGrades();
                break;
            case 3:
                printf("Logging out...\n");
                return;
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}

// Function to view all student grades
void viewAllGrades() {
    char line[MAX_LINE];
    FILE *file = fopen("data/students.csv", "r");

    if (!file) {
        printf("Error opening student database!\n");
        return;
    }

    printf("\n===== All Student Grades =====\n");
    while (fgets(line, sizeof(line), file)) {
        int sID, english, kiswahili, science, maths, socialStudies;
        char name[MAX_NAME_LEN], admNo[MAX_ID_LEN];

        sscanf(line, "%d,%49[^,],%9[^,],%d,%d,%d,%d,%d", 
               &sID, name, admNo, &english, &kiswahili, &science, &maths, &socialStudies);

        printf("%d. %s (ADM: %s) - Eng: %d, Kis: %d, Sci: %d, Math: %d, Soc: %d\n",
               sID, name, admNo, english, kiswahili, science, maths, socialStudies);
    }

    fclose(file);
}

// Function to modify student grades
void modifyStudentGrades() {
    char admNo[MAX_ID_LEN], line[MAX_LINE], newData[21][MAX_LINE];
    int found = 0, i = 0;
    FILE *file = fopen("data/students.csv", "r");

    if (!file) {
        printf("Error opening student database!\n");
        return;
    }

    printf("Enter Student Admission Number to modify grades: ");
    scanf("%s", admNo);

    // Read all data into memory
    while (fgets(line, sizeof(line), file)) {
        int sID, english, kiswahili, science, maths, socialStudies;
        char name[MAX_NAME_LEN], existingAdmNo[MAX_ID_LEN];

        sscanf(line, "%d,%49[^,],%9[^,],%d,%d,%d,%d,%d", 
               &sID, name, existingAdmNo, &english, &kiswahili, &science, &maths, &socialStudies);

        if (strcmp(admNo, existingAdmNo) == 0) {
            printf("Current Grades for %s (ADM: %s)\n", name, existingAdmNo);
            printf("English: %d, Kiswahili: %d, Science: %d, Maths: %d, Social Studies: %d\n",
                   english, kiswahili, science, maths, socialStudies);

            // Take new grades
            printf("Enter new grades (English Kiswahili Science Maths SocialStudies): ");
            scanf("%d %d %d %d %d", &english, &kiswahili, &science, &maths, &socialStudies);
            sprintf(newData[i], "%d,%s,%s,%d,%d,%d,%d,%d\n", 
                    sID, name, existingAdmNo, english, kiswahili, science, maths, socialStudies);
            found = 1;
        } else {
            strcpy(newData[i], line);
        }
        i++;
    }
    fclose(file);

    if (!found) {
        printf("Student with Admission No %s not found!\n", admNo);
        return;
    }

    // Write modified data back to file
    file = fopen("data/students.csv", "w");
    for (int j = 0; j < i; j++) {
        fputs(newData[j], file);
    }
    fclose(file);

    printf("Grades updated successfully!\n");
}
