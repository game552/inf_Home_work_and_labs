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

    printf("Input string: ");
    if (fgets(text, sizeof(text), stdin) == NULL) {
            printf("Input error.\n");
            return 1;
        }

    size_t len = strlen(text);
    if (len > 0 && text[len - 1] == '\n') text[len - 1] = '\0';

    int i = 0;
    int short_count = 0;
    while (text[i] != '\0') {
        while (text[i] != '\0' && is_space(text[i])) i++;
        char word[81];
        int j = 0;
        while (text[i] != '\0' && !is_space(text[i]) && j < (int)sizeof(word) - 1) {
            word[j++] = text[i++];
        }
        word[j] = '\0';

        if (j > 0) {
            list_insert_sorted(dll, word);
            if (j < 5) short_count++;
        }
    }

    list_print_forward(dll);
    list_print_backward(dll);
    printf("\nTotal words: %d\n", list_size(dll));
    printf("Words with length < 5: %d\n", short_count);

    list_destroy(dll);
    return 0;
}