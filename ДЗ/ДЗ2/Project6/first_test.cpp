//#include <stdio.h>
//#include <stdlib.h>
//
//// Подключаем оригинальную функцию
//#include "print_func.h"  // если есть .h
//// либо напрямую:
//
//// Функция для проверки двух массивов
//int arrays_equal(int* a, int* b, int n) {
//    for (int i = 0; i < n; i++) {
//        if (a[i] != b[i]) {
//            return 0;
//        }
//    }
//    return 1;
//}
//
//// Тест 1: пустой массив
//void test_empty_array() {
//    int arr[1] = { 0 };
//    shaker_sort(arr, 0);
//    printf("Test EmptyArray: OK\n");
//}
//
//// Тест 2: один элемент
//void test_one_element() {
//    int arr[] = { 42 };
//    int expected[] = { 42 };
//    shaker_sort(arr, 1);
//    if (arrays_equal(arr, expected, 1))
//        printf("Test OneElement: OK\n");
//    else
//        printf("Test OneElement: FAIL\n");
//}
//
//// Тест 3: уже отсортирован
//void test_already_sorted() {
//    int arr[] = { 1, 2, 3, 4, 5 };
//    int expected[] = { 1, 2, 3, 4, 5 };
//    shaker_sort(arr, 5);
//    if (arrays_equal(arr, expected, 5))
//        printf("Test AlreadySorted: OK\n");
//    else
//        printf("Test AlreadySorted: FAIL\n");
//}
//
//// Тест 4: обратный порядок
//void test_reverse_sorted() {
//    int arr[] = { 5, 4, 3, 2, 1 };
//    int expected[] = { 1, 2, 3, 4, 5 };
//    shaker_sort(arr, 5);
//    if (arrays_equal(arr, expected, 5))
//        printf("Test ReverseSorted: OK\n");
//    else
//        printf("Test ReverseSorted: FAIL\n");
//}
//
//// Тест 5: дубликаты
//void test_duplicates() {
//    int arr[] = { 4, 2, 2, 4, 1, 1 };
//    int expected[] = { 1, 1, 2, 2, 4, 4 };
//    shaker_sort(arr, 6);
//    if (arrays_equal(arr, expected, 6))
//        printf("Test Duplicates: OK\n");
//    else
//        printf("Test Duplicates: FAIL\n");
//}
//
//// Тест 6: отрицательные числа
//void test_negatives() {
//    int arr[] = { 0, -5, 3, -1, 2 };
//    int expected[] = { -5, -1, 0, 2, 3 };
//    shaker_sort(arr, 5);
//    if (arrays_equal(arr, expected, 5))
//        printf("Test Negatives: OK\n");
//    else
//        printf("Test Negatives: FAIL\n");
//}
//
//// Тест 7: все одинаковые
//void test_all_equal() {
//    int arr[] = { 7, 7, 7, 7, 7 };
//    int expected[] = { 7, 7, 7, 7, 7 };
//    shaker_sort(arr, 5);
//    if (arrays_equal(arr, expected, 5))
//        printf("Test AllEqual: OK\n");
//    else
//        printf("Test AllEqual: FAIL\n");
//}
//
//// Главная функция, запускающая все тесты
////int main() {
////    printf("Running shaker_sort tests...\n\n");
////
////    test_empty_array();
////    test_one_element();
////    test_already_sorted();
////    test_reverse_sorted();
////    test_duplicates();
////    test_negatives();
////    test_all_equal();
////
////    printf("\nAll tests finished.\n");
////    return 0;
////}
