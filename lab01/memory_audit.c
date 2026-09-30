#include <stdio.h>

int main(void) {
    printf("--- SIZEOF TYPES ---\n");
    printf("sizeof(char):      %zu byte(s)\n", sizeof(char));
    printf("sizeof(short):     %zu byte(s)\n", sizeof(short));
    printf("sizeof(int):       %zu byte(s)\n", sizeof(int));
    printf("sizeof(long):      %zu byte(s)\n", sizeof(long));
    printf("sizeof(long long): %zu byte(s)\n", sizeof(long long));
    printf("sizeof(float):     %zu byte(s)\n", sizeof(float));
    printf("sizeof(double):    %zu byte(s)\n", sizeof(double));
    printf("sizeof(void*):     %zu byte(s)\n\n", sizeof(void*));

    unsigned char byte_test = 255;

    printf("--- OVERFLOW DEMO ---\n");
    printf("Before (+0): DEC = %u, HEX = 0x%02X\n", byte_test, byte_test);

    byte_test = byte_test + 1;

    printf("After  (+1): DEC = %u, HEX = 0x%02X\n", byte_test, byte_test);

    return 0;
}