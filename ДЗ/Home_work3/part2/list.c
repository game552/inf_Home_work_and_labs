#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

DoublyLinkedList* list_create(void) {
    DoublyLinkedList* list = (DoublyLinkedList*)malloc(sizeof(DoublyLinkedList));
    if (list == NULL) {
        fprintf(stderr, "Error: Memory allocation for list failed\n");
        return NULL;
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

Node* node_create(const char* data) {
    Node* node = (Node*)malloc(sizeof(Node));
    if (node == NULL) {
        fprintf(stderr, "Error: Memory allocation for node failed\n");
        return NULL;
    }

    size_t data_len = strlen(data) + 1;
    node->data = (char*)malloc(data_len);
    if (node->data == NULL) {
        fprintf(stderr, "Error: Memory allocation for data failed\n");
        free(node);
        return NULL;
    }

    strcpy_s(node->data, data_len, data);
    node->next = NULL;
    node->prev = NULL;
    return node;
}

void list_append(DoublyLinkedList* list, const char* data) {
    if (list == NULL) return;

    Node* new_node = node_create(data);
    if (new_node == NULL) return;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    list->size++;
}

void list_prepend(DoublyLinkedList* list, const char* data) {
    if (list == NULL) return;

    Node* new_node = node_create(data);
    if (new_node == NULL) return;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
    }
    else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    list->size++;
}

void list_insert_at(DoublyLinkedList* list, int index, const char* data) {
    if (list == NULL || index < 0 || index > list->size) return;

    if (index == 0) {
        list_prepend(list, data);
        return;
    }
    if (index == list->size) {
        list_append(list, data);
        return;
    }

    Node* new_node = node_create(data);
    if (new_node == NULL) return;

    Node* current = list->head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }

    new_node->next = current->next;
    new_node->prev = current;
    current->next->prev = new_node;
    current->next = new_node;
    list->size++;
}

void list_remove_at(DoublyLinkedList* list, int index) {
    if (list == NULL || index < 0 || index >= list->size || list->head == NULL) {
        return;
    }

    Node* current;

    if (index == 0) {
        current = list->head;
        if (list->head->next != NULL) {
            list->head->next->prev = NULL;
            list->head = list->head->next;
        }
        else {
            list->head = NULL;
            list->tail = NULL;
        }
    }
    else if (index == list->size - 1) {
        current = list->tail;
        list->tail->prev->next = NULL;
        list->tail = list->tail->prev;
    }
    else {
        current = list->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
    }

    free(current->data);
    free(current);
    list->size--;
}

char* list_get(DoublyLinkedList* list, int index) {
    if (list == NULL || index < 0 || index >= list->size) {
        return NULL;
    }

    Node* current;

    if (index < list->size / 2) {
        current = list->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    }
    else {
        current = list->tail;
        for (int i = list->size - 1; i > index; i--) {
            current = current->prev;
        }
    }

    return current->data;
}

void list_print_forward(DoublyLinkedList* list) {
    if (list == NULL) return;

    printf("List (forward order): ");
    Node* current = list->head;
    while (current != NULL) {
        printf("[%s] <-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void list_print_backward(DoublyLinkedList* list) {
    if (list == NULL) return;

    printf("List (backward order): ");
    Node* current = list->tail;
    while (current != NULL) {
        printf("[%s] <-> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}


int list_size(DoublyLinkedList* list) {
    return (list == NULL) ? 0 : list->size;
}

void list_clear(DoublyLinkedList* list) {
    if (list == NULL) return;

    Node* current = list->head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp->data);
        free(temp);
    }
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}


void list_destroy(DoublyLinkedList* list) {
    if (list == NULL) return;

    list_clear(list);
    free(list);
}

int list_find(DoublyLinkedList* list, const char* data) {
    if (list == NULL) return -1;

    Node* current = list->head;
    int index = 0;
    while (current != NULL) {
        if (strcmp(current->data, data) == 0) {
            return index;
        }
        current = current->next;
        index++;
    }
    return -1;
}

void list_insert_sorted(DoublyLinkedList* list, const char* data) {
    if (list == NULL) return;

    Node* new_node = node_create(data);
    if (new_node == NULL) return;

    if (list->head == NULL) {
        list->head = new_node;
        list->tail = new_node;
        list->size++;
        return;
    }

    Node* current = list->head;
    while (current != NULL && strcmp(current->data, data) <= 0) {
        current = current->next;
    }

    if (current == list->head) {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    else if (current == NULL) {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
    else {
        new_node->next = current;
        new_node->prev = current->prev;
        current->prev->next = new_node;
        current->prev = new_node;
    }

    list->size++;
}