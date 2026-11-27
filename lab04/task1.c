#include <locale.h>
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>
#endif

void init_console_utf8(void);
unsigned long long fibonacci(unsigned int n);
unsigned int update_max_request(unsigned int n);
void print_result(unsigned int n, unsigned long long fib_val, unsigned int max_n);

int main(void) {
    init_console_utf8();

    unsigned int n = 0;

    printf("Введіть номер числа Фібоначчі (n >= 0): ");
    fflush(stdout);
    if (scanf("%u", &n) != 1) {
        fprintf(stderr, "Помилка вводу.\n");
        return 1;
    }

    unsigned int max_n = update_max_request(n);
    unsigned long long fib_val = fibonacci(n);
    print_result(n, fib_val, max_n);

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

unsigned int update_max_request(unsigned int n) {
    static unsigned int max_requested = 0;
    static int has_requests = 0;

    if (!has_requests || n > max_requested) {
        max_requested = n;
        has_requests = 1;
    }

    return max_requested;
}

unsigned long long fibonacci(unsigned int n) {
    if (n == 0U) {
        return 0ULL;
    }
    if (n == 1U) {
        return 1ULL;
    }

    unsigned long long prev2 = 0ULL;
    unsigned long long prev1 = 1ULL;
    unsigned long long current = 0ULL;

    for (unsigned int i = 2U; i <= n; ++i) {
        current = prev1 + prev2;
        prev2 = prev1;
        prev1 = current;
    }

    return current;
}

void print_result(unsigned int n, unsigned long long fib_val, unsigned int max_n) {
    printf("F(%u) = %llu\n", n, fib_val);
    printf("Максимальне запитане значення n (static): %u\n", max_n);
    fflush(stdout);
}