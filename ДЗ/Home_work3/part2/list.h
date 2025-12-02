#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Node {
    char *data;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} DoublyLinkedList;

DoublyLinkedList* list_create(void);

Node* node_create(const char *data);

void list_append(DoublyLinkedList *list, const char *data);

void list_prepend(DoublyLinkedList *list, const char *data);

void list_insert_at(DoublyLinkedList *list, int index, const char *data);

void list_insert_sorted(DoublyLinkedList *list, const char *data);

void list_remove_at(DoublyLinkedList *list, int index);

char* list_get(DoublyLinkedList *list, int index);

void list_print_forward(DoublyLinkedList *list);

void list_print_backward(DoublyLinkedList *list);

int list_size(DoublyLinkedList *list);

void list_clear(DoublyLinkedList *list);

void list_destroy(DoublyLinkedList *list);

int list_find(DoublyLinkedList *list, const char *data);

#endif