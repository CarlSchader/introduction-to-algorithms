#include<stdio.h>
#include<string.h>
#include"stack.h"
#include"queue.h"

using namespace std;

int main() {
    stack *s = newStack(10);

    printf("example input:\npush hello\npop\ninput: ");

    char command[32];
    char input[32];
    while (scanf("%s %s", command, input) != EOF) {
        printf("\n");
        try {
            if (strcmp(command, "push") == 0) {
                push(s, input);
            } else if (strcmp(command, "pop") == 0) {
                pop(s);
            } else {
                printf("incorrect input\n");
            }
        } catch (const char *e) {
            printf("%s\n", e);
        }
        printf("length: %ld\n", s->tail - s->array);
        printf("input: ");
    }
}