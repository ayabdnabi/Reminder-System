/*
Name: Aya Abdul Nabi
Student ID: 251307615
Assignment5
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "reminder.h"
#include "linked_list.h"

struct Month month; // declare global month structure

// function used to print calendar
void printCalendar(){
    printf("Sun Mon Tue Wed Thu Fri Sat\n");

    // print leading spaces
    for (int i = 0; i < month.start_day; i++){
        printf("    ");
    }

    // if the day has a reminder, add parenthesis around it, otherwise print it normally
    for (int i = 1; i <= month.month_days; i++){
        if (month.reminders[i - 1] != NULL){
            printf("(%2d)", i);
        } else {
            printf(" %2d ", i);
        }

        // after 7 days, go to a new line
        if ((i + month.start_day) % 7 == 0){
            printf("\n");
        }
    }

    printf("\n");
}

// function used to initialize the month with the current month
void initializeMonth(){
    // get current time
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    // set the month index depending on the month
    month.month_index = t->tm_mon;

    t->tm_mday = 1; // set the day to the first day of the month to determine the starting day
    mktime(t);
    month.start_day = t->tm_wday; // get first weekday for the month

    // calculate total number of days in the month
    month.month_days = t->tm_mday;
    while (t->tm_mon == month.month_index){
        month.month_days = t->tm_mday;
        t->tm_mday++;
        mktime(t);
    }
}

// function used to return the weekday for a specific day in the month
char* currentWeekDay(int day) {
    int weekday_index = (month.start_day + (day - 1)) % 7; // get the weekday index for the given day
    
    // return the corresponding weekday name
    switch (weekday_index) {
        case 0: 
            return "Sun";
        case 1:
            return "Mon";
        case 2: 
            return "Tue";
        case 3: 
            return "Wed";
        case 4: 
            return "Thu";
        case 5: 
            return "Fri";
        case 6: 
            return "Sat";
        default: 
            return ""; 
    }
}
