#include"queue.h"
#include<string.h>
#include<stdio.h>

using namespace std;

queue *newQueue(int size) {
    queue *s = new queue();
    s->array = new void *[size];
    s->head = s->array - 1;
    s->tail = s->array;
    s->size = size;
    return s;
}

void enqueue(queue *s, void *x) {
    if (s->tail == s->head && s->count > 0) {
        s->tail = ;
        throw "Error: queue overflow";
    } else {
        *s->tail = x;
        s->tail++;
        s->count++;
    }
}

void *dequeue(queue *s) {
    if (s->head == s->tail) {
        throw "Error: queue underflow";
    } else {
        void *x = *s->head;
        s->head++;
        if (s->head - s->array == s->size) {
            s->head = s->array;
        }
        s->count--;
        return x;
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
