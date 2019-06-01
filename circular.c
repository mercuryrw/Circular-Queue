#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pop(char **queue, int max, int *front, int *rear) {
    if (*front == -1) {
        printf("Queue empty\n\n");
        return 0;
    }

    printf("POP: %s\n", queue[*front]);
    *front = (*front + 1) % (max + 1);

    if (*front == (*rear + 1) % (max+1)) {
        *front = -1;
        *rear = -1;
    }
    
    return 1;
}

int push(char **queue, int max, int *front, int *rear, char *value) {
    if ((*rear + 1)%(max + 1) == *front || (*rear + 1) == max + 1 && *front == -1) {
        printf("Queue full\n\n");
        return 0;
    }

    if (*front == -1) {
        *front = 0;
    }

    printf("PUSH: %s\n", value);
    *rear = (*rear + 1)%(max + 1);

    char* newvalue = malloc(sizeof(value));
    strcpy(newvalue, value);
    queue[*rear] = newvalue;

    return 1;
}

int main() {
    int max = 4;
    char* queue[max];
    int front = -1;
    int rear = -1;

    int strlen = 15;

    int quit = 0;
    while (!quit) {
        char input[strlen];
        printf("> ");
        fgets(input, strlen, stdin);
        if (input[0] == '\n') {
            pop(queue, max, &front, &rear);
        }
        else if (input[0] == 'q') {
            quit = 1;
        }
        else {
            push(queue, max, &front, &rear, input);
        }
    }

    return 0;
}