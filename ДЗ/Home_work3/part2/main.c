#include <stdio.h>
#include "list.h"
#include <locale.h>

int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

int main(){
    setlocale(LC_ALL, "");
    char text[80];
    DoublyLinkedList* dll = list_create();

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
        int j = 0;
        char word[80] = "";
        while (text[i] != '\0' && !is_space(text[i])) {
            word[j] = text[i];
            i++;
        }
        word[i + 1] = '\0';
        list_append(dll, word);

    }
    list_print_forward(dll);
    return 0;
}