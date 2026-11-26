#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 15

int main(void) {
    int arr[SIZE];

    srand((unsigned int)time(NULL));

    for (int i = 0; i < SIZE; i++) {
        arr[i] = (rand() % 101) - 50;
    }

    printf("Вихідний масив:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");

    int max_val = arr[0];
    int max_idx = 0;
    for (int i = 1; i < SIZE; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
            max_idx = i;
        }
    }

    int first_zero = -1;
    int last_zero = -1;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] == 0) {
            if (first_zero == -1) {
                first_zero = i;
            }
            last_zero = i;
        }
    }

    long long prod_between_zeros = 1;
    int has_between = 0;
    if (first_zero != -1 && last_zero != -1 && last_zero - first_zero > 1) {
        has_between = 1;
        for (int i = first_zero + 1; i < last_zero; i++) {
            prod_between_zeros *= arr[i];
        }
    }

    printf("\nМаксимальний елемент: %d (індекс: %d)\n", max_val, max_idx);
    if (first_zero == -1 || first_zero == last_zero) {
        printf("У масиві менше двох нулів — добуток між першим і останнім нулем не обчислюється.\n");
    } else if (!has_between) {
        printf("Між першим (індекс %d) та останнім (індекс %d) нулями немає елементів.\n",
               first_zero, last_zero);
    } else {
        printf("Перший нуль за індексом %d, останній — за індексом %d.\n",
               first_zero, last_zero);
        printf("Добуток елементів між ними: %lld\n", prod_between_zeros);
    }

    printf("\nСтан масиву після обробки:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%4d", arr[i]);
    }
    printf("\n");

    return 0;
}