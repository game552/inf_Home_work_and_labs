#include <stdio.h>
#include <stdlib.h>

void shaker_sort(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    int swapped = 1;

    while (left < right&& swapped) {
        swapped = 0;

        for (int i = left; i < right; i++) {
            if (arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swapped = 1;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if (arr[i] < arr[i - 1]) {
                int temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
                swapped = 1;
            }
        }
        left++;
    }
}

int first_task_streams(FILE* in, FILE* out, void* (*alloc_fn)(size_t)) {
    int n;
    fprintf(out, "Input array size: ");
    if (fscanf(in, "%d", &n) != 1 || n <= 0) {
        fprintf(out, "Invalid array size\n");
        return 1;
    }

    int* arr_i = (int*)alloc_fn(n * sizeof(int));
    if (arr_i == NULL) {
        fprintf(out, "Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        fprintf(out, "Input digit for position %d: ", i);
        if (fscanf(in, "%d", &arr_i[i]) != 1) {
            fprintf(out, "Invalid input\n");
            free(arr_i);
            return 1;
        }
    }

    shaker_sort(arr_i, n);

    fprintf(out, "Array elements: ");
    for (int i = 0; i < n; i++) {
        fprintf(out, "%d ", arr_i[i]);
    }
    fprintf(out, "\n");

    free(arr_i);
    return 0;
}

int first_task() {
    return first_task_streams(stdin, stdout, malloc);
}
