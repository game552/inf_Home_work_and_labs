<<<<<<< HEAD
#include <stdio.h>

// Функция для проверки, является ли символ пробелом
int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Функция для преобразования символа в верхний регистр
char to_upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

// Функция для проверки, является ли символ латинской буквой
int is_alpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Функция для подсчета слов
int count_words(const char* text) {
    int count = 0;
    int i = 0;
    
    while (text[i] != '\0') {
        // Пропускаем пробелы
        while (text[i] != '\0' && is_space(text[i])) {
            i++;
        }
        
        // Если достигли конца строки, выходим
        if (text[i] == '\0') {
            break;
        }
        
        // Находим начало слова
        int start = i;
        char first_char = text[start];
        
        // Находим конец слова
        while (text[i] != '\0' && !is_space(text[i])) {
            i++;
        }
        
        int end = i - 1;
        
        // Получаем последний символ слова
        char last_char = text[end];
        
        // Проверяем условия
        if (is_alpha(first_char) && is_alpha(last_char) && 
            to_upper(first_char) == 'B' && to_upper(last_char) == 'K') {
            count++;
        }
    }
    
    return count;
}

void run_tests() {
    printf("=== ТЕСТИРОВАНИЕ ===\n");
    
    // Тест 1: Обычный случай
    const char* test1 = "Bank Book Bark Bike Cake Break Brick";
    int result1 = count_words(test1);
    printf("Тест 1: '%s'\n", test1);
    printf("Ожидаемый результат: 4 (Bank, Book, Break, Brick)\n");
    printf("Фактический результат: %d\n", result1);
    printf("Статус: %s\n\n", result1 == 4 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 2: Разные регистры
    const char* test2 = "bLACK block bOOK bANk";
    int result2 = count_words(test2);
    printf("Тест 2: '%s'\n", test2);
    printf("Ожидаемый результат: 3 (bLACK, block, bOOK)\n");
    printf("Фактический результат: %d\n", result2);
    printf("Статус: %s\n\n", result2 == 3 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 3: Множественные пробелы
    const char* test3 = "  Bank   Book    Break   ";
    int result3 = count_words(test3);
    printf("Тест 3: '%s'\n", test3);
    printf("Ожидаемый результат: 3 (Bank, Book, Break)\n");
    printf("Фактический результат: %d\n", result3);
    printf("Статус: %s\n\n", result3 == 3 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 4: Слова без подходящих условий
    const char* test4 = "Apple Cat Dog Elephant";
    int result4 = count_words(test4);
    printf("Тест 4: '%s'\n", test4);
    printf("Ожидаемый результат: 0\n");
    printf("Фактический результат: %d\n", result4);
    printf("Статус: %s\n\n", result4 == 0 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 5: Пустая строка
    const char* test5 = "";
    int result5 = count_words(test5);
    printf("Тест 5: '%s'\n", test5);
    printf("Ожидаемый результат: 0\n");
    printf("Фактический результат: %d\n", result5);
    printf("Статус: %s\n\n", result5 == 0 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 6: Только пробелы
    const char* test6 = "   \t  \n  ";
    int result6 = count_words(test6);
    printf("Тест 6: '%s'\n", test6);
    printf("Ожидаемый результат: 0\n");
    printf("Фактический результат: %d\n", result6);
    printf("Статус: %s\n\n", result6 == 0 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 7: Слова с другими знаками препинания
    const char* test7 = "Bank, Book. Break! Brick?";
    int result7 = count_words(test7);
    printf("Тест 7: '%s'\n", test7);
    printf("Ожидаемый результат: 4 (Bank, Book, Break, Brick)\n");
    printf("Фактический результат: %d\n", result7);
    printf("Статус: %s\n\n", result7 == 4 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 8: Слово из одной буквы B или K
    const char* test8 = "B K";
    int result8 = count_words(test8);
    printf("Тест 8: '%s'\n", test8);
    printf("Ожидаемый результат: 0 (B не заканчивается на K, K не начинается на B)\n");
    printf("Фактический результат: %d\n", result8);
    printf("Статус: %s\n\n", result8 == 0 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 9: Слово BK
    const char* test9 = "BK bK Bk bk";
    int result9 = count_words(test9);
    printf("Тест 9: '%s'\n", test9);
    printf("Ожидаемый результат: 4\n");
    printf("Фактический результат: %d\n", result9);
    printf("Статус: %s\n\n", result9 == 4 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
}

int main() {
    run_tests();
    return 0;
=======
#include <stdio.h>

// Функция для проверки, является ли символ пробелом
int is_space(char c) {
    return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

// Функция для преобразования символа в верхний регистр
char to_upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}

// Функция для проверки, является ли символ латинской буквой
int is_alpha(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

// Функция для подсчета слов
int count_words(const char* text) {
    int count = 0;
    int i = 0;
    
    while (text[i] != '\0') {
        // Пропускаем пробелы
        while (text[i] != '\0' && is_space(text[i])) {
            i++;
        }
        
        // Если достигли конца строки, выходим
        if (text[i] == '\0') {
            break;
        }
        
        // Находим начало слова
        int start = i;
        char first_char = text[start];
        
        // Находим конец слова
        while (text[i] != '\0' && !is_space(text[i])) {
            i++;
        }
        
        int end = i - 1;
        
        // Получаем последний символ слова
        char last_char = text[end];
        
        // Проверяем условия
        if (is_alpha(first_char) && is_alpha(last_char) && 
            to_upper(first_char) == 'B' && to_upper(last_char) == 'K') {
            count++;
        }
    }
    
    return count;
}

void run_tests() {
    printf("=== ТЕСТИРОВАНИЕ ===\n");
    
    // Тест 1: Обычный случай
    const char* test1 = "Bank Book Bark Bike Cake Break Brick";
    int result1 = count_words(test1);
    printf("Тест 1: '%s'\n", test1);
    printf("Ожидаемый результат: 4 (Bank, Book, Break, Brick)\n");
    printf("Фактический результат: %d\n", result1);
    printf("Статус: %s\n\n", result1 == 4 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 2: Разные регистры
    const char* test2 = "bLACK block bOOK bANk";
    int result2 = count_words(test2);
    printf("Тест 2: '%s'\n", test2);
    printf("Ожидаемый результат: 3 (bLACK, block, bOOK)\n");
    printf("Фактический результат: %d\n", result2);
    printf("Статус: %s\n\n", result2 == 3 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 3: Множественные пробелы
    const char* test3 = "  Bank   Book    Break   ";
    int result3 = count_words(test3);
    printf("Тест 3: '%s'\n", test3);
    printf("Ожидаемый результат: 3 (Bank, Book, Break)\n");
    printf("Фактический результат: %d\n", result3);
    printf("Статус: %s\n\n", result3 == 3 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 4: Слова без подходящих условий
    const char* test4 = "Apple Cat Dog Elephant";
    int result4 = count_words(test4);
    printf("Тест 4: '%s'\n", test4);
    printf("Ожидаемый результат: 0\n");
    printf("Фактический результат: %d\n", result4);
    printf("Статус: %s\n\n", result4 == 0 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 5: Пустая строка
    const char* test5 = "";
    int result5 = count_words(test5);
    printf("Тест 5: '%s'\n", test5);
    printf("Ожидаемый результат: 0\n");
    printf("Фактический результат: %d\n", result5);
    printf("Статус: %s\n\n", result5 == 0 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 6: Только пробелы
    const char* test6 = "   \t  \n  ";
    int result6 = count_words(test6);
    printf("Тест 6: '%s'\n", test6);
    printf("Ожидаемый результат: 0\n");
    printf("Фактический результат: %d\n", result6);
    printf("Статус: %s\n\n", result6 == 0 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 7: Слова с другими знаками препинания
    const char* test7 = "Bank, Book. Break! Brick?";
    int result7 = count_words(test7);
    printf("Тест 7: '%s'\n", test7);
    printf("Ожидаемый результат: 4 (Bank, Book, Break, Brick)\n");
    printf("Фактический результат: %d\n", result7);
    printf("Статус: %s\n\n", result7 == 4 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 8: Слово из одной буквы B или K
    const char* test8 = "B K";
    int result8 = count_words(test8);
    printf("Тест 8: '%s'\n", test8);
    printf("Ожидаемый результат: 0 (B не заканчивается на K, K не начинается на B)\n");
    printf("Фактический результат: %d\n", result8);
    printf("Статус: %s\n\n", result8 == 0 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
    
    // Тест 9: Слово BK
    const char* test9 = "BK bK Bk bk";
    int result9 = count_words(test9);
    printf("Тест 9: '%s'\n", test9);
    printf("Ожидаемый результат: 4\n");
    printf("Фактический результат: %d\n", result9);
    printf("Статус: %s\n\n", result9 == 4 ? "ПРОЙДЕН" : "НЕ ПРОЙДЕН");
}

int main() {
    run_tests();
    return 0;
>>>>>>> 14514800b40a6510d5b3b1f207df1603b4a671c5
}