#include "queue_v1.h"

Queue* queue_create(void) {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    if (q == NULL) {
        fprintf(stderr, "Error: failed to allocate memory\n");
        return NULL;
    }
    q->capacity = QUEUE_INITIAL_CAPACITY;
    q->data = (int*)malloc(q->capacity * sizeof(int));
    if (q->data == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for array\n");
        free(q);
        return NULL;
    }
    q->front = 0;
    q->rear = -1;
    q->count = 0;
    printf("Queue created, capacity = %d\n", QUEUE_INITIAL_CAPACITY);
    return q;
}

bool queue_expand(Queue* q) {
    int new_capacity = q->capacity * QUEUE_GROWTH_FACTOR;
    int* new_data = malloc(new_capacity * sizeof(int));
    if (new_data == NULL) {
        fprintf(stderr, "Error: failed to allocate memory for array\n");
        return false;
    }
    for (int i = 0; i < q->count; i++) {
        new_data[i] = q->data[(q->front + i) % q->capacity];
    }
    free(q->data);
    printf("Expansion: %d -> %d\n", q->capacity, new_capacity);
    q->data = new_data;
    q->capacity = new_capacity;
    q->front = 0;
    q->rear = (q->count > 0) ? q->count - 1 : -1;
    return true;
}

bool queue_is_empty(Queue* q) {
    if (q == NULL) {
        fprintf(stderr, "Error: queue is not initialized\n");
        return false;
    }
    return q->count == 0;
}

bool queue_is_full(Queue* q) {
    if (q == NULL) {
        fprintf(stderr, "Error: queue is not initialized\n");
        return false;
    }
    return q->count == q->capacity;
}

int queue_get_capacity(Queue* q) {
    return (q == NULL) ? -1 : q->capacity;
}

int queue_size(Queue* q) {
    if (q == NULL) {
        fprintf(stderr, "Error: queue is not initialized\n");
        return -1;
    }
    return q->count;
}

void queue_destroy(Queue* q) {
    if (q != NULL) {
        if (q->data != NULL) {
            free(q->data);
        }
        free(q);
    }
}

void queue_print_info(Queue* q) {
    if (q == NULL) {
        fprintf(stderr, "Error: queue is not initialized\n");
        return;
    }

    printf("Queue Status:\n");
    printf("  Empty: %s\n", queue_is_empty(q) ? "yes" : "no");
    printf("  Full: %s\n", queue_is_full(q) ? "yes" : "no");
    printf("  Size: %d / %d\n", queue_size(q), q->capacity);
    printf("  Front: %d, Rear: %d\n\n", q->front, q->rear);
    printf("  Capacity: %d / %d\n", q->count, q->capacity);
}

void queue_clear(Queue* q) {
    if (q == NULL) {
        fprintf(stderr, "Error: queue is not initialized\n");
        return;
    }
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

bool queue_enqueue(Queue* q, int value) {
    if (q == NULL) {
        fprintf(stderr, "Error: queue is not initialized\n");
        return false;
    }

    if (queue_is_full(q)) {
        if (!  queue_expand(q)) {
            fprintf(stderr, "Error: failed to expand queue\n");
            return false;
        }
    }

    if (queue_is_empty(q)) {
        q->front = 0;
        q->rear = 0;
    }
    else {
        q->rear = (q->rear + 1) % q->capacity;
    }

    q->data[q->rear] = value;
    q->count++;

    printf("Element added: %d (size: %d/%d)\n",
        value, q->count, q->capacity);
    return true;
}

bool queue_dequeue(Queue* q, int* value) {
    if (q == NULL) {
        fprintf(stderr, "Error: queue is not initialized\n");
        return false;
    }

    if (queue_is_empty(q)) {
        fprintf(stderr, "Error: queue is empty, nothing to remove\n");
        return false;
    }

    if (value == NULL) {
        fprintf(stderr, "Error: pointer value is not initialized\n");
        return false;
    }

    *value = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->count--;

    if (queue_is_empty(q)) {
        q->front = 0;
        q->rear = -1;
    }

    return true;
}

bool queue_front(Queue* q, int* value) {
    if (q == NULL) {
        fprintf(stderr, "Error: queue is not initialized\n");
        return false;
    }

    if (queue_is_empty(q)) {
        fprintf(stderr, "Error: queue is empty\n");
        return false;
    }

    if (value == NULL) {
        fprintf(stderr, "Error: pointer value is not initialized\n");
        return false;
    }

    *value = q->data[q->front];
    printf("First element: %d\n", *value);
    return true;
}

void queue_print(Queue* q) {
    if (queue_is_empty(q)) {
        printf("Queue: [empty]\n");
        return;
    }

    printf("Queue: ");
    for (int i = 0; i < q->count; i++) {
        int idx = (q->front + i) % q->capacity;
        printf("%d ", q->data[idx]);
    }
    printf("\n");
}

void queue_shrink_to_fit(Queue* q) {
    if (q == NULL) {
        fprintf(stderr, "Error: queue is not initialized\n");
        return;
    }
    if (queue_is_empty(q)) {
        int* new_data = malloc(QUEUE_INITIAL_CAPACITY * sizeof(int));
        if (new_data == NULL) {
            fprintf(stderr, "Error: failed to allocate memory\n");
            return;
        }
        free(q->data);
        q->data = new_data;
        q->capacity = QUEUE_INITIAL_CAPACITY;
        q->front = 0;
        q->rear = -1;
    }
    else if (q->count < q->capacity){
        int* new_data = malloc(q->count * sizeof(int));
        if (new_data == NULL) {
            fprintf(stderr, "Error: failed to allocate memory for array\n");
            return;
        }
        for (int i = 0; i < q->count; i++) {
            new_data[i] = q->data[(q->front + i) % q->capacity];
        }
        free(q->data);
        q->data = new_data;
        q->capacity = q->count;
        q->front = 0;
        q->rear = q->count - 1;
    }
}