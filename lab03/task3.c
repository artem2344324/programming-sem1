#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 256

int main(void) {
    system("chcp 65001 > nul");

    char str[BUFFER_SIZE];

    printf("Enter text: ");

    if (fgets(str, sizeof(str), stdin) == NULL) {
        printf("Error reading input.\n");
        return 1;
    }

    int word_count = 0;
    int in_word = 0; // Прапорець: 1 — перебуваємо всередині слова, 0 — поза словом

    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) { 

        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\r') {
            if (!in_word) {
                in_word = 1;     // Початок нового слова
                word_count++;
            }
        } else {
            in_word = 0;         // Пробіл або розділювач — слово закінчилося
        }
    }

    printf("Total number of words: %d\n", word_count);

    return 0;
}