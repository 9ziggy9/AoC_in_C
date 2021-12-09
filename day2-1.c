#include <stdio.h>
#include <string.h>

typedef struct Position {
    int x;
    int depth;
} Position;

typedef struct Instruction {
    char action[10];
    int magnitude;
} Instruction;

int main(void) {
    Position position;
    position.x = 0;
    position.depth = 0;

    int i = 0;

    Instruction instruction_set[2000];

    FILE* inst;
    inst = fopen("input.txt", "r");

    if (inst == NULL) {
        printf("Cannot open instructions.\n");
        return 1;
    }

    while ((fscanf(inst, "%s %d\n", instruction_set[i].action,
                   &instruction_set[i].magnitude)) != EOF) {
        i++;
    }

    instruction_set[i].magnitude = '\0';

    for (i = 0; instruction_set[i].magnitude != '\0'; i++) {
        char* a = instruction_set[i].action;
        if (!strcmp(a, "down")) position.depth += instruction_set[i].magnitude;
        if (!strcmp(a, "up")) position.depth -= instruction_set[i].magnitude;
        if (!strcmp(a, "forward")) position.x += instruction_set[i].magnitude;
    }

    printf("current position: (%d, %d, %d)\n", position.x,
                                            position.depth,
                                            position.depth * position.x);

    return 0;
}
