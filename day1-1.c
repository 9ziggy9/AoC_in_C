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

    for (i = 1; depth_measurements[i] != '\0'; i++) {
        if (depth_measurements[i] > depth_measurements[i - 1])
            large_count++;
    }

    printf("%d\n", large_count);

    return 0;
}
