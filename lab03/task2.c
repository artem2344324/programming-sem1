#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 4
#define COLS 4

int main(void) {
    // Налаштування кодування консолі
    system("chcp 65001 > nul");

    int matrix[ROWS][COLS];
    
    // Ініціалізація генератора випадкових чисел
    srand((unsigned int)time(NULL));

    // Заповнення матриці випадковими числами з діапазону [-50; 50] 
    // з дотриманням стандарту лінійного проходу пам'яті (Row-Major Order)
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = (rand() % 101) - 50;
        }
    }

    printf("Initial matrix (%dx%d):\n", ROWS, COLS);
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    for (int j = 0; j < COLS; j++) {
        int min_col_val = matrix[0][j];
        for (int i = 1; i < ROWS; i++) {
            if (matrix[i][j] < min_col_val) {
                min_col_val = matrix[i][j];
            }
        }
        printf("Minimum element in column %d: %d\n", j, min_col_val);
    }
    printf("\n");

    for (int j = 0; j < COLS; j++) {
        int temp = matrix[0][j];
        matrix[0][j] = matrix[ROWS - 1][j];
        matrix[ROWS - 1][j] = temp;
    }

    printf("Matrix after swapping first and last rows:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%6d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}