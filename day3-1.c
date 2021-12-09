#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NUM_BITS 12

char kth_bit(int i, int k) {
 return (i & (1 << k)) >> k;
}

int from_binary(const char* s) {
    return (int) strtol(s, NULL, 2);
}

int main(void) {
    FILE* bit_file;
    bit_file = fopen("input.txt", "r");

    char binary_dump[5000][13];
    int i = 0;
    long gamma = 0;   // 0000 0000 0000
    long epsilon = 0; // 0000 0000 0000

    if (bit_file == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    while (fscanf(bit_file, "%s\n", binary_dump[i]) != EOF) i++;
    fclose(bit_file);
    strcpy(binary_dump[i], "done");

    short k = 0;
    while (k < NUM_BITS) {
        long one_count = 0;
        long zero_count = 0;
        for (i = 1; strcmp(binary_dump[i], "done"); i++) {
            int ival = from_binary(binary_dump[i]);
            if (kth_bit(ival, k)) one_count++;
            else zero_count++;
        }
        if (one_count > zero_count) gamma ^= (1 << k);
        if (one_count < zero_count) epsilon ^= (1 << k);
        k++;
    }

    printf("%ld %ld %ld\n", gamma, epsilon, gamma*epsilon);


    return 0;
}
