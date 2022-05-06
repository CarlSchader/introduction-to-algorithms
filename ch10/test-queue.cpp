#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"queue.h"

using namespace std;

int main() {
    queue *s = newQueue(10);

    printf("example input:\npush hello\npop\ninput: ");

    char command[32];
    char input[32];
    while (scanf("%s %s", command, input) != EOF) {
        printf("\n");
        try {
            if (strcmp(command, "push") == 0) {
                char *newString = (char *)malloc(sizeof(input));
                strcpy(newString, input);
                enqueue(s, newString);
                printf("pushed: %s\n", newString);
            } else if (strcmp(command, "pop") == 0) {
                char *poppedString = (char *)dequeue(s);
                printf("popped: %s\n", poppedString);
                free(poppedString);
            } else {
                printf("incorrect input\n");
            }
        } catch (const char *e) {
            printf("%s\n", e);
        }
        printf("input: ");
    }
}