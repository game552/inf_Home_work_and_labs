#ifndef QUEUE_V1_H
#define QUEUE_V1_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_INITIAL_CAPACITY 5
#define QUEUE_GROWTH_FACTOR 2

typedef struct {
    int* data;
    int front;
    int rear;
    int count;
    int capacity;
} Queue;

Queue* queue_create(void);
bool queue_is_empty(Queue* q);
bool queue_is_full(Queue* q);
int queue_size(Queue* q);
void queue_destroy(Queue* q);
void queue_print_info(Queue* q);
bool queue_enqueue(Queue* q, int value);
bool queue_dequeue(Queue* q, int* value);
bool queue_front(Queue* q, int* value);
void queue_print(Queue* q);
bool queue_expand(Queue* q);
void queue_shrink_to_fit(Queue* q);
void queue_clear(Queue* q);

#endif