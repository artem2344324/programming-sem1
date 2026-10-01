#include <stdio.h>
#include <windows.h>

int main(void) {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    double t_c, t_f, t_k;

    printf("Введіть температуру в градусах Цельсія (T_C): ");
    
    if (scanf("%lf", &t_c) != 1) {
        printf("Помилка: введено некоректне число!\n");
        return 1;
    }

    if (t_c < -273.15) {
        printf("Помилка: температура не може бути нижчою за абсолютний нуль (-273.15 °C)!\n");
        return 1;
    }

    t_f = t_c * (9.0 / 5.0) + 32.0;
    t_k = t_c + 273.15;

    printf("\n--- Результати перетворення ---\n");
    printf("Цельсій (T_C):   %.2f °C\n", t_c);
    printf("Фаренгейт (T_F): %.2f °F\n", t_f);
    printf("Кельвін (T_K):   %.2f K\n", t_k);

    return 0;
}