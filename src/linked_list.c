/*
Name: Aya Abdul Nabi
Student ID: 251307615
Assignment5
*/

#include "linked_list.h"
 
 // function to add a node with a node with a specified date 
void addNode(struct Node **head, const char *data) {
    // allocate memory for the new node
    struct Node *addingNode = (struct Node *)malloc(sizeof(struct Node));
    if (!addingNode) {
        printf("Memory allocation failed\n"); // print if memory allocation fails
        return;
    }
    // copy the data into the new node's data field
    strcpy(addingNode->data, data);
    addingNode->next = NULL; // its next will point to null since it is the last node

    // if the list is empty, set the new node as the head
    if (*head == NULL) {
        *head = addingNode;
    } else {
        // otherwise traverse to the last node and add it accordingly
        struct Node *currentNode = *head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = addingNode;
    }
}

// function used to delete node from the list
void deleteNode(struct Node **head, const char *data){
    struct Node *currentNode = *head, *prev = NULL;

    // traverse the list to find the node with the matching data
    while (strcmp(currentNode ->data, data)!= 0 && currentNode !=NULL)
    {
        prev = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL){
        printf("Remainder not found\n"); // if node not found, print error message
    }

    // iff the node to delete is not the head, adjust the previous node's next pointer
    if (prev != NULL){
        prev->next = currentNode->next;
    } else {
        *head = currentNode->next; // if it is, update it accordingly
    }

    free(currentNode);
}

// function used to print the data of all nodes in linked list
void printList(struct Node *head){
    struct Node *current = head;
    // traverse and print each node's data
    while (current != NULL){
        printf("- %s\n", current->data);
        current = current->next;
    }
}