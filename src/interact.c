/*
Name: Aya Abdul Nabi
Student ID: 251307615
Assignment5
*/

#include "reminder.h"
#include "linked_list.h"
#include "interact.h"

// array of month names used for display purposes
const char *MONTHS[] = {
        "January", "February", "March", "April", "May", "June", 
        "July", "August", "September", "October", "November", "December"
    };

// function to read user input for adding reminders
void readReminders(){
    char userReminder[100], userInput[100];
    int day;

    // prompt the user to enter a day with its corresponding reminder
    printf("Enter day and reminder: (0 to quit): ");
    fgets(userInput, sizeof(userInput), stdin);
    sscanf(userInput, "%d %[^\n]", &day, userReminder);
    userReminder[strcspn(userReminder, "\n")] = 0;

    // if user enters zero, prgram finishes. save the reminder to the file
    if (day == 0){
        writingToFile();
        exit(0);
    }

    // if the user enters an invalid date, prompt it to enter a valid one constantly until they do
    while (day < 0 || day > month.month_days){
        printf("Invalid day:: The day must be >= 1 or <= %d\n", month.month_days);
        printf("Enter a day and reminder: (0 to quit): ");
        fgets(userInput, sizeof(userInput), stdin);
        sscanf(userInput, "%d %[^\n]", &day, userReminder);
    }

    // add the reminder to the specified date
    addNode(&month.reminders[day - 1], userReminder);

    
    // print the reminder and calendar
    printCalendar();
    printReminders();
}

// function used to print the reminders
void printReminders(){
    printf("\n%s Reminders:\n", MONTHS[month.month_index]);
    // loop through each day of the month
    for (int i = 0; i < month.month_days; i++){
        struct Node* curr = month.reminders[i];

        // If there are reminders for the day, print them
        if (curr != NULL){
            printf("%s %2d:: (%d) %s\n", currentWeekDay(i + 1), i + 1, 1, curr->data);
            curr = curr->next;

            int count = 2;
            //  print additional reminders for the same day
            while (curr != NULL){
               printf("         (%d) %s\n", count++, curr->data);
               curr = curr->next;
            }
        }
    }
    printf("-------------------\n");
}

// function used to read reminders from the file
void readingFromFile(){
    FILE* readFile = fopen("reminders.txt", "r");
    // if file does not exist, there is nothing to read
    if (readFile == NULL){
        return;
    }

    // read reminders from the file and add them to the linked list 
    int day;
    char reminder[100];
    while (fscanf(readFile, "%d %[^\n]", &day, reminder) == 2) {
        addNode(&month.reminders[day - 1], reminder);
    }
    fclose(readFile);
}

// function used to write the reminders to the file 
void writingToFile(){
    FILE* file = fopen("reminders.txt", "w");
    // if file cannot be opened, print an error message
    if (file == NULL) {
        printf("Error saving reminders.\n");
        return;
    }

    // loop through each day of the month and write reminder files
    for (int i = 0; i < month.month_days; i++) {
        struct Node* temp = month.reminders[i];
        while (temp != NULL) {
            fprintf(file, "%d %s\n", i + 1, temp->data);
            temp = temp->next;
        }
    }
    fclose(file);
}
