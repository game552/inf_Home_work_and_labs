#include "queue_v1.h"

int main(void) {
    Queue* qu = queue_create();
    if (qu == NULL) {
        fprintf(stderr, "Error: failed to allocate memory\n");
        return 1;
    }
    else {
        printf("Queue created successfully\n\n");
    }
    
    int number;
    int first_negative_index = -1;  
    int last_negative_index = -1;   
    int index = 0;                   

    printf("Enter a sequence of integers (Ctrl+D to end):\n");
    printf("-> ");

    while (scanf("%d", &number) == 1) {

        if (!queue_enqueue(qu, number)) {
            fprintf(stderr, "Error: failed to add element\n");
            queue_destroy(qu);
            return 1;
        }

        if (number < 0) {
            if (first_negative_index == -1) {
                first_negative_index = index;
            }
            last_negative_index = index;
        }

        index++;
    }

    printf("\n");

    if (first_negative_index == -1) {
        printf("Error: no negative numbers in the sequence!\n");
        queue_destroy(qu);
        return 1;
    }

    printf("Found:\n");
    printf("First negative at position: %d\n", first_negative_index);
    printf("Last negative at position: %d\n\n", last_negative_index);

    printf("Result: ");

    int value;
    int current_index = 0;

    while (!  queue_is_empty(qu)) {
        if (! queue_dequeue(qu, &value)) {
            fprintf(stderr, "Error: failed to remove element\n");
            queue_destroy(qu);
            return 1;
        }
        if (current_index >= first_negative_index &&
            current_index <= last_negative_index) {
            printf("%d ", value);
        }

        current_index++;
    }

    printf("\n\n");

    queue_destroy(qu);

    printf("Program completed successfully\n");

    return 0;
}