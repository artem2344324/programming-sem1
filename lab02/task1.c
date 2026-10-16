#include <stdio.h>
#include <math.h>

int main() {
    double x_start, x_end, dx;

    printf("Enter x_start: ");
    if (scanf("%lf", &x_start) != 1) return 1;

    printf("Enter x_end: ");
    if (scanf("%lf", &x_end) != 1) return 1;

    printf("Enter step (dx): ");
    if (scanf("%lf", &dx) != 1) return 1;

    // Обов'язкова валідація вхідних параметрів
    if (x_start > x_end || dx <= 0) {
        fprintf(stderr, "Error: invalid parameters (x_start must be <= x_end, and dx > 0).\n");
        return 1;
    }

    // Виведення шапки таблиці
    printf("\n------------------------------------\n");
    printf("|      X      |       Y(X)         |\n");
    printf("------------------------------------\n");

    // Цикл табулювання з урахуванням граничної точки
    for (double x = x_start; x <= x_end + 1e-9; x += dx) {
        double y;
        
        if (x <= 0.0) {
            y = -x;
        } else if (x > 0.0 && x <= 2.0) {
            y = x * x;
        } else {
            y = 4.0;
        }

        printf("| %11.4lf | %16.4lf |\n", x, y);
    }

    printf("------------------------------------\n");
    return 0;
}