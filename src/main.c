#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"
#include "admin.h"

#define MAX_NAME_LEN 50
#define MAX_ID_LEN 10

// Function prototypes
void displayMenu();
int loginAsStudent();
int loginAsAdmin();

int main() {
    int choice, id;

    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // Consume newline

        switch (choice) {
            case 1:
                id = loginAsStudent();
                if (id != -1) {
                    studentMenu(id);
                }
                break;
            case 2:
                id = loginAsAdmin();
                if (id != -1) {
                    adminMenu();
                }
                break;
            case 3:
                printf("Exiting system...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Display main menu
void displayMenu() {
    printf("\n====================\n");
    printf(" SCHOOL GRADING SYSTEM \n");
    printf("====================\n");
    printf("1. Login as Student\n");
    printf("2. Login as Admin\n");
    printf("3. Exit\n");
}

// Student login function
int loginAsStudent() {
    char enteredID[MAX_ID_LEN];
    char line[100];
    FILE *file = fopen("data/students.csv", "r");

    if (!file) {
        printf("Error opening student database!\n");
        return -1;
    }

    printf("Enter your Admission Number: ");
    scanf("%s", enteredID);

    while (fgets(line, sizeof(line), file)) {
        char id[MAX_ID_LEN], name[MAX_NAME_LEN];
        int sID;
        sscanf(line, "%d,%49[^,],%9s", &sID, name, id);

        if (strcmp(enteredID, id) == 0) {
            fclose(file);
            printf("Welcome, %s!\n", name);
            return sID; // Return student ID
        }
    }

    fclose(file);
    printf("Invalid Admission Number!\n");
    return -1;
}

// Admin login function
int loginAsAdmin() {
    char enteredID[MAX_ID_LEN];
    char line[100];
    FILE *file = fopen("data/admins.csv", "r");

    if (!file) {
        printf("Error opening admin database!\n");
        return -1;
    }

    printf("Enter your Admin ID: ");
    scanf("%s", enteredID);

    while (fgets(line, sizeof(line), file)) {
        char id[MAX_ID_LEN], name[MAX_NAME_LEN];
        int aID;
        sscanf(line, "%d,%49[^,],%9s", &aID, name, id);

        if (strcmp(enteredID, id) == 0) {
            fclose(file);
            printf("Welcome, %s!\n", name);
            return aID; // Return admin ID
        }
    }

    fclose(file);
    printf("Invalid Admin ID!\n");
    return -1;
}
