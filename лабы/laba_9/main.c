#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    FILE *input_file, *output_file;
    char line[1024];
    char word[256];
    int word_count = 0;
    int filtered_count = 0;
    
    const char *input_path = "input.txt";
    const char *output_path = "output.txt";
    

    input_file = fopen(input_path, "r");
    if (input_file == NULL) {
        printf("Ошибка: не удалось открыть файл %s\n", input_path);
        return 1;
    }
    
    output_file = fopen(output_path, "w");
    if (output_file == NULL) {
        printf("Ошибка: не удалось открыть файл %s\n", output_path);
        fclose(input_file);
        return 1;
    }
    
    printf("Обработка файла: %s\n", input_path);
    
    while (fgets(line, sizeof(line), input_file) != NULL) {
        
        int i = 0;
        int word_index = 0;
        
        for (i = 0; i <= (int)strlen(line); i++) {
            char current_char = line[i];
            
            if (isalnum(current_char)) {
                word[word_index++] = current_char;
            } else {
                if (word_index > 0) {
                    word[word_index] = '\0';
                    word_count++;
                    
                    int word_length = strlen(word);
                    
                    if (word_length < 3) {
                        fprintf(output_file, "%s\n", word);
                        filtered_count++;
                    }
                
                    word_index = 0;
                }
            }
        }
    }
    
    fclose(input_file);
    fclose(output_file);
    

    printf("Обработка завершена!\n");
    printf("Всего слов обработано: %d\n", word_count);
    printf("Слов записано в output.txt: %d\n", filtered_count);
    printf("Результат сохранён в: %s\n", output_path);
    
    return 0;
}