#include <stdio.h>
#include <stdlib.h>

// Define a struct for a singly linked list node
typedef struct Node {
    int data; // Data to be stored in the node
    struct Node* next; // Pointer to the next node in the list
} Node;

// Function to insert a new node at the beginning of the list
void insert(Node** head, int data) {
    // Create a new node and allocate memory for it
    Node* new_node = (Node*)malloc(sizeof(Node));

    // Set the data for the new node
    new_node->data = data;

    // Set the next pointer of the new node to the current head of the list
    new_node->next = *head;

    // Set the head of the list to the new node
    *head = new_node;
}

// Function to delete a node from the list
void delete(Node** head, int data) {
    // Create a temporary pointer to traverse the list
    Node* current = *head;

    // Create a pointer to keep track of the previous node
    Node* previous = NULL;

    // Traverse the list until the end or until the node to be deleted is found
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    // If the node was not found, return without deleting anything
    if (current == NULL) {
        return;
    }

    // If the node to be deleted is the head of the list, set the new head to the next node
    if (previous == NULL) {
        *head = current->next;
    }

    // Otherwise, set the previous node's next pointer to skip over the node to be deleted
    else {
        previous->next = current->next;
    }

    // Free the memory allocated for the deleted node
    free(current);
}

// Function to search for a node in the list
Node* search(Node* head, int data) {
    // Traverse the list until the end or until the node is found
    while (head != NULL) {
        if (head->data == data) {
            return head;
        }
        head = head->next;
    }

    // If the node was not found, return NULL
    return NULL;
}

// Function to print the contents of the list
void print_list(Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Sample main function to demonstrate usage
int main() {
    // Create an empty list
    Node* head = NULL;

    // Insert some nodes into the list
    insert(&head, 5);
    insert(&head, 10);
    insert(&head, 15);
    insert(&head, 20);

    // Print the contents of the list
    printf("List after insertion: ");
    print_list(head);

    // Delete a node from the list
    delete(&head, 10);

    // Print the contents of the list
    printf("List after deletion: ");
    print_list(head);

    // Search for a node in the list
    Node* search_result = search(head, 15);
    if (search_result != NULL) {
        printf("Node found: %d\n", search_result->data);
    }
    else {
        printf("Node not found.\n");
    }

    return 0;
}