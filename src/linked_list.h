/*
Name: Aya Abdul Nabi
Student ID: 251307615
Assignment5
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// defining a node structure
struct Node 
{
    char data[256];  // used to hold data in each node      
    struct Node *next; // pointer to the next node in list
};

// function headers to add a node, delete a node, free all nodes, and print the data of all nodes
void addNode(struct Node **head, const char *data);

void deleteNode(struct Node **head, const char *data);

void freeAll(struct Node **head);

void printList(struct Node *head);

#endif