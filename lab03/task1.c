#include <stdio.h>
#include <stdlib.h>

int main(void) {
    // Налаштування кодування UTF-8 для правильного відображення кирилиці в консолі Windows
    system("chcp 65001 > nul");

    int n;
    printf("Введіть кількість елементів масиву: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Помилка: некоректний розмір масиву.\n");
        return 1;
    }

    int arr[n];
    printf("Введіть %d елементів масиву:\n", n);
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        if (scanf("%d", &arr[i]) != 1) {
            printf("Помилка введення даних.\n");
            return 1;
        }
    }

    // Обчислення суми та пошук мінімального/максимального елементів
    int sum = 0;
    int min = arr[0];
    int max = arr[0];

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    double average = (double)sum / n;

    // Вивід результатів
    printf("\n--- Результати обробки масиву ---\n");
    printf("Введений масив: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Мінімальний елемент: %d\n", min);
    printf("Максимальний елемент: %d\n", max);
    printf("Сума елементів: %d\n", sum);
    printf("Середнє арифметичне: %.2f\n", average);

    return 0;
}