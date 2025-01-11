#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    char *data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head; // pointer to head node

struct Node* GetNewNode(char *str) {
    /* Local variables in functions will be cleared from memory when function call finishes 
    So we will create a node in dynamic memory/heap section of memory. 
    Anything in heap is not cleared unless we explicitly free it.
    To do this, we will use malloc to reserve some memory in heap. */
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = *str; // same as (*newNode).data = *str;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(char *str) {
    struct Node* newNode = GetNewNode(*str);
    if (head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(char *str) {
    struct Node* newNode = GetNewNode(*str);
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

struct Node* findNode(char *str) {
    if (head == NULL) {
        return;
    }
    if (head->data == *str) {
        return head;
    }
    struct Node* temp = head;
    while(temp->next != NULL) {
        if (temp->data == *str) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

void printList() {
    if (head == NULL) {
        return;
    }
    if (head->next == NULL) {
        printf(head->data);
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL) {
        printf(temp->data);
        temp = temp->next;
    }
}

int main() {
    
}