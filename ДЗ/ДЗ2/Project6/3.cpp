#include <stdio.h>
#include <locale.h>
#include "print_func.h"

void print_float_mass(float* matrix, int rows) {
    printf("mass size = %d:\n", rows);
    for (int i = 0; i < rows; i++) {
        printf("%8.2f ", matrix[i]);
    }

    printf("\n");
}

void find_elements(float arr[10], int index, float result[10], int* result_size) {
    int c = 0;
    for (int i = 0; i < 10; i++) {
        if (arr[i] > arr[index]) {
            result[c++] = arr[i];
        }
    }
    *result_size = c;
}

float sum_arr(float arr[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

int main_thered() {
    setlocale(LC_ALL, "");
    const int N = 10;
    float A[10];
    int i1, i2, i3;

    printf("Введите 10 вещественных чисел массива A:\n");
    for (int i = 0; i < N; i++) {
        printf("A[%d] = ", i);
        if (scanf_s("%f", &A[i]) != 1) {
            printf("Некорректный ввод.\n");
            return 1;
        }
    }

    printf("Введите три индекса (0–9): ");
    if (scanf_s("%d %d %d", &i1, &i2, &i3) != 3 ||
        i1 < 0 || i1 >= N || i2 < 0 || i2 >= N || i3 < 0 || i3 >= N) {
        printf("Ошибка: некорректные индексы!\n");
        return 1;
    }

    int indexes[3] = { i1, i2, i3 };
    float result[10];
    int result_size;

    for (int k = 0; k < 3; k++) {
        int idx = indexes[k];
        find_elements(A, idx, result, &result_size);

        printf("\nИндекс %d (A[%d] = %.2f):\n", idx, idx, A[idx]);

        if (result_size == 0) {
            printf("Нет элементов больше A[%d].\n", idx);
        }
        else {
            print_float_mass(result, result_size);
            printf("Сумма этих элементов = %.2f\n", sum_arr(result, result_size));
        }
    }

    return 0;
}
