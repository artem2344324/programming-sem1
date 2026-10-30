#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define SIZE 15

int main(void) {
    int arr[SIZE];
    
    // Ініціалізація генератора випадкових чисел
    srand((unsigned int)time(NULL));

    // Заповнення масиву випадковими числами з діапазону [-50; 50]
    for (int i = 0; i < SIZE; i++) {
        arr[i] = (rand() % 101) - 50;
    }

    // Виведення вихідного масиву в один рядок
    printf("Вихідний масив:\n[ ");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n\n");

    // 1. Пошук мінімального за модулем елемента (ініціалізація нульовим елементом)
    int min_abs = arr[0];
    int min_index = 0;
    
    for (int i = 1; i < SIZE; i++) {
        if (abs(arr[i]) < abs(min_abs)) {
            min_abs = arr[i];
            min_index = i;
        }
    }
    
    printf("Мінімальний за модулем елемент: %d (його модуль: %d, індекс: %d)\n", 
           min_abs, abs(min_abs), min_index);

    // 2. Знаходження суми елементів, розташованих після першого від'ємного
    int first_neg_index = -1;
    for (int i = 0; i < SIZE; i++) {
        if (arr[i] < 0) {
            first_neg_index = i;
            break;
        }
    }

    int sum_after_neg = 0;
    if (first_neg_index != -1) {
        printf("Перший від'ємний елемент: %d знайдено під індексом %d\n", 
               arr[first_neg_index], first_neg_index);
        
        if (first_neg_index < SIZE - 1) {
            for (int i = first_neg_index + 1; i < SIZE; i++) {
                sum_after_neg += arr[i];
            }
            printf("Сума елементів після першого від'ємного: %d\n", sum_after_neg);
        } else {
            printf("Перший від'ємний елемент є останнім у масиві, після нього немає елементів.\n");
        }
    } else {
        printf("У масиві немає від'ємних елементів.\n");
    }

    return 0;
}