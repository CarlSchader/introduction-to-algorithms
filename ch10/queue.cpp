#include"queue.h"
#include<string.h>
#include<stdio.h>

using namespace std;

queue *newQueue(int size) {
    queue *s = new queue();
    s->array = new void *[size];
    s->head = s->array + size;
    s->tail = s->array;
    s->size = size;
    return s;
}

void enqueue(queue *s, void *x) {
    printf("tail: %ld\n", s->tail - s->array);
    if (s->tail == s->head) {
        throw "Error: queue overflow";
    }
    if (s->tail - s->array == s->size) {
        s->tail = s->array;
    }
    *s->tail = x;
    s->tail++;
}

void *dequeue(queue *s) {
    printf("head: %ld\n", s->head - s->array);
    void **original = s->head;
    if (s->head - s->array == s->size) {
        s->head = s->array;
    } else {
        s->head++;
    }
    if (s->head == s->tail) {
        s->head = original;
        throw "Error: queue underflow";
    } else {
        return *s->head;
    }
}

// void toString(queue *s, char *buffer) {
//     buffer[0] = '\0';
//     void **head = s->head;
//     head++;
//     if (head - s->array == s->size) {
//         head = s->array;
//     }
//     while (head != s->tail) {
//         if (head - s->array == s->size) {
//             head = s->array;
//         }
//         char elemString[100];
//         sprintf(elemString, "element: %s\n", (char *)*head);
//         strcat(buffer, elemString);
        
//         head++;
//         if (head - s->array == s->size) {
//             head = s->array;
//         }
//     }
//     char countString[32];
//     sprintf(countString, "count: %d\n", s->count);
//     strcat(buffer, countString);
// }
