/*
Name: Aya Abdul Nabi
Student ID: 251307615
Assignment5
*/

#include <signal.h>
#include "reminder.h"
#include "interact.h"

// signal handler function to manage termination signals
void handle_signal(int signal) {
    if (signal == SIGINT || signal == SIGTERM) {
        // print message if user terminates program
        printf("\nProgram terminated...\n");
        printf("Writing to file...\n");
        writingToFile();
        exit(0); // exit the program with a success status
    }
}


int main() {
    // set up the signal handlers
    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    // initialize the month and read reminders from files
    initializeMonth();
    readingFromFile();

    while (1) {
        // read reminders as long as the user interacts with the program
        readReminders();
    }

    return 0;
}
