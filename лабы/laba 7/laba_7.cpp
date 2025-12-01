#include <stdio.h>
#include <string.h>
#include <locale.h>

int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

char to_upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

int is_alpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int main() {
    setlocale(LC_ALL, "ru");
    char text[1024];

    printf("Введите строку: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
            printf("Ошибка ввода.\n");
            return 1;
        }
    int i = 0;
    int count = 0;
    while (text[i] != '\0') {
        while (text[i] != '\0' && is_space(text[i])) {
            i++;
        }
        int start = i;
        char first_char = text[start];
        while (text[i] != '\0' && !is_space(text[i])) {
            i++;
        }
        int end = i - 1;
        char last_char = text[end];
        if (is_alpha(first_char) && is_alpha(last_char) &&
            to_upper(first_char) == 'B' && to_upper(last_char) == 'K') {
            count++;
        }
    }
    printf("Колличесвто слов начинающихся на K кончающихся на B: ");
    printf("%d", count);
    return 0;
}
