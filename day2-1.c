#include <stdio.h>

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

    Instruction instruction_set[5000];

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
        printf("%s %d\n", instruction_set[i].action, instruction_set[i].magnitude);
    }

    return 0;
}
