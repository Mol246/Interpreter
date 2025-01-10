#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head; // pointer to head node

struct Node* GetNewNode(int x) {
    /* Local variables in functions will be cleared from memory when function call finishes 
    So we will create a node in dynamic memory/heap section of memory. 
    Anything in heap is not cleared unless we explicitly free it.
    To do this, we will use malloc to reserve some memory in heap. */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x; // same as (*newNode).data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int x) {
    struct Node* newNode = GetNewNode(x);
    if (head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(int x) {
    struct Node* newNode = GetNewNode(x);
    if (head == NULL) {
        head = newNode;
        return;
    }
    if (head->next == NULL) {
        head->next = newNode;
        newNode->prev = head;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next; // Traverse to last node/tail
    }
    temp->next = newNode;
    newNode->prev = temp;
    return;
}

void removeHead() {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        head = NULL;
        return;
    }
    head = head->next;
    head->prev = NULL;
    return;
}

void removeTail() {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        head = NULL;
        return;
    }
    struct Node* temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next; // Traverse to second last node
    }
    temp->next = NULL;
    return;
}

int main() {
    
}