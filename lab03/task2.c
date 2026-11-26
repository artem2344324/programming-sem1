#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define N 4

static void print_matrix(int mat[N][N], const char *title) {
    printf("\n%s:\n", title);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%6d", mat[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    int mat[N][N];
    srand((unsigned int)time(NULL));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            mat[i][j] = (rand() % 101) - 50;
        }
    }

    print_matrix(mat, "Матриця до обробки");

    long long sum_below_main = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i > j) {
                sum_below_main += mat[i][j];
            }
            if (i + j == N - 1) {
                mat[i][j] = 0;
            }
        }
    }

    printf("\nСума елементів нижче головної діагоналі: %lld\n", sum_below_main);
    print_matrix(mat, "Матриця після обнулення побічної діагоналі");

    return 0;
}