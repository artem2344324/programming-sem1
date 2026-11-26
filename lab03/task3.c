#include <stdio.h>

#define MAX_LEN 255

static char to_lower_ascii(char c) {
    if (c >= 'A' && c <= 'Z') {
        return (char)(c + ('a' - 'A'));
    }
    return c;
}

int main(void) {
    char str[MAX_LEN + 1];
    char clean[MAX_LEN + 1];

    printf("Введіть рядок тексту (до %d символів): ", MAX_LEN);
    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Помилка вводу.\n");
        return 1;
    }

    int i = 0;
    int clean_len = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n' && str[i] != '\r') {
            clean[clean_len] = to_lower_ascii(str[i]);
            clean_len++;
        }
        i++;
    }
    clean[clean_len] = '\0';
    str[MAX_LEN] = '\0';

    int is_palindrome = 1;
    int left = 0;
    int right = clean_len - 1;

    while (left < right) {
        if (clean[left] != clean[right]) {
            is_palindrome = 0;
            break;
        }
        left++;
        right--;
    }

    printf("Текст без пробілів: \"%s\"\n", clean);
    if (clean_len == 0) {
        printf("Рядок порожній або містить лише пробіли.\n");
    } else if (is_palindrome) {
        printf("Результат: рядок Є паліндромом.\n");
    } else {
        printf("Результат: рядок НЕ є паліндромом.\n");
    }

    return 0;
}