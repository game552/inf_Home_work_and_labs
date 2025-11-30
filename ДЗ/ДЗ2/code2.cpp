#include <stdio.h>
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


void analyze_matrix(char arr[9][9], int n) {
    printf("\nПромежуточные результаты:\n");
    for (int i = 0; i < n; i++) {
        int digits = 0;
        int others = 0;


        for (int j = 0; j < n; j++) {
            if (arr[i][j] >= '0' && arr[i][j] <= '9')
                digits++;
            else
                others++;
        }

        printf("Строка %d: цифр = %d, других символов = %d -> ", i + 1, digits, others);

        if (digits > others)
            printf("больше цифр.\n");
        else
            printf("больше других символов.\n");
    }

    printf("\nСтроки, где цифр больше, чем других символов:\n");
    int found = 0;
    for (int i = 0; i < n; i++) {
        int digits = 0;
        int others = 0;
        for (int j = 0; j < n; j++) {
            if (arr[i][j] >= '0' && arr[i][j] <= '9')
                digits++;
            else
                others++;
        }
        if (digits > others) {
            printf("→ Строка %d\n", i + 1);
            found = 1;
        }
    }
    if (!found)
        printf("Нет строк с преобладанием цифр.\n");
}

int main() {
    setlocale(LC_ALL, "");
    int n;

    printf("Введите размер матрицы (1–9): ");
    if (scanf_s("%d", &n) != 1 || n <= 0 || n > 9) {
        printf("Ошибка: некорректный размер.\n");
        return 1;
    }

    while (getchar() != '\n');

    char arr[9][9];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Введите символ [%d][%d]: ", i, j);
            if (scanf_s(" %c", &arr[i][j], 1) != 1) {
                printf("Ошибка ввода.\n");
                return 1;
            }
        }
    }

    print_char_matrix(arr, n, n);
    analyze_matrix(arr, n);

    return 0;
}
