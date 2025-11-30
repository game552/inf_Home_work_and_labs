#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


void print_char_matrix(char matrix[9][9], int rows, int cols) {
    printf("Matrix %dx%d:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}