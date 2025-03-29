/*
Name: Aya Abdul Nabi
Student ID: 251307615
Assignment5
*/

#ifndef REMINDER_H
#define REMINDER_H

#include "linked_list.h" // include the header for the linked_list operations

// structure used in order to represent a month
struct Month
{
   // month index, starting day, amount of days in month, and reminders for each day
   int month_index;
   int start_day;
   int month_days;
   struct Node* reminders[31];
};

extern struct Month month; // external variable to hold the month's data

// function to print the calendar, initialize the month, and to return the given week day
void printCalendar();
void initializeMonth();
char* currentWeekDay(int day);

#endif
