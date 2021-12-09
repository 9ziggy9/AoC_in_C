#include <stdio.h>

int main(void) {
    FILE* file;
    file = fopen("input.txt", "r");

    int depth_measurements[5000];
    int i = 0;
    int large_count = 0;

    if (file == NULL) {
        printf("Cannot open file.\n");
        return 1;
    }

    while (fscanf(file, "%d", &depth_measurements[i]) != EOF) i++;
    fclose(file);
    depth_measurements[i] = '\0';

    int previous_sum = -1;

    for (i = 0; depth_measurements[i] != '\0'; i++) {
        int sum = 0;
        int window = 0;
        while (window < 3) {
            sum += depth_measurements[i + window];
            ++window;
        }
        if (previous_sum > 0 &&  sum > previous_sum) large_count++;
        previous_sum = sum;
    }

    printf("%d\n", large_count);

    return 0;
}
