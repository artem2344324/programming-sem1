#include <locale.h>
#include <stdint.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

void init_console_utf8(void);
uint32_t set_bit(uint32_t reg, unsigned int bit);
uint32_t clear_bit(uint32_t reg, unsigned int bit);
uint32_t toggle_bit(uint32_t reg, unsigned int bit);
int check_bit(uint32_t reg, unsigned int bit);
void print_binary(uint32_t reg);

int main(void) {
    init_console_utf8();

    uint32_t reg = 0x00000020U; 

    printf("Початковий стан регістра:\n");
    print_binary(reg);

    reg = set_bit(reg, 0U);
    printf("\nПісля встановлення біта 0:\n");
    print_binary(reg);

    reg = clear_bit(reg, 5U);
    printf("\nПісля скидання біта 5:\n");
    print_binary(reg);

    reg = toggle_bit(reg, 9U);
    printf("\nПісля інвертування біта 9:\n");
    print_binary(reg);

    int bit31_state = check_bit(reg, 31U);
    printf("\nСтан біта 31: %d\n", bit31_state);

    reg = set_bit(reg, 31U);
    printf("Після встановлення біта 31:\n");
    print_binary(reg);
    printf("Стан біта 31 тепер: %d\n", check_bit(reg, 31U));
    fflush(stdout);

    return 0;
}

void init_console_utf8(void) {
    setlocale(LC_ALL, "uk_UA.UTF-8");
    setlocale(LC_CTYPE, ".UTF-8");
#ifdef _WIN32
    SetConsoleOutputCP(65001U);
    SetConsoleCP(65001U);
#endif
}

uint32_t set_bit(uint32_t reg, unsigned int bit) {
    if (bit >= 32U) {
        return reg;
    }
    return reg | (1U << bit);
}

uint32_t clear_bit(uint32_t reg, unsigned int bit) {
    if (bit >= 32U) {
        return reg;
    }
    return reg & ~(1U << bit);
}

uint32_t toggle_bit(uint32_t reg, unsigned int bit) {
    if (bit >= 32U) {
        return reg;
    }
    return reg ^ (1U << bit);
}

int check_bit(uint32_t reg, unsigned int bit) {
    if (bit >= 32U) {
        return 0;
    }
    return ((reg & (1U << bit)) != 0U) ? 1 : 0;
}

void print_binary(uint32_t reg) {
    printf("HEX: 0x%08X | BIN: ", reg);
    for (int i = 31; i >= 0; --i) {
        putchar(((reg >> i) & 1U) ? '1' : '0');
        if (i > 0 && (i % 4) == 0) {
            putchar('_');
        }
    }
    putchar('\n');
}