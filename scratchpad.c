#include <stdio.h>

int main(void) {
    int bit = 0;

    bit ^= (1 << 2);
    bit ^= (1 << 3);

    printf("0000 goes to 1100 = 12: %d", bit);
}
