#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "print_func.h"






/*


*/
int main() {
    int choice;

    printf("Which part of task do you prefer to launch?\n");
    printf("1 - first part\n");
    printf("2 - second part\n");
    printf("3 - third part\n");
    printf("Your choice: ");


    if (scanf_s("%d", &choice) != 1) {
        printf("Invalid input! Please enter a number.\n");
        return 1;
    }

    switch (choice) {
    case 1: {
        first_task();
        break;
    }
    case 2: {
        main_second();
        break;
    }
    case 3: {
        main_thered();
        break;
    }
    }
	return 0;
}