#include"queue.h"

using namespace std;

queue *newQueue(int size) {
    queue *s = new queue();
    s->array = new void *[size];
    s->head = s->array;
    s->tail = s->array;
    s->size = size;
    return s;
}

void enqueue(queue *s, void *x) {
    if (s->tail - s->array == s->size) {
        throw "Error: queue overflow";
    } else {
        *s->tail = x;
        ++(s->tail);
    }
}

void *dequeue(queue *s) {
    if (s->tail == s->array) {
        throw "Error: queue underflow";
    } else {
        void *x = *s->tail;
        --(s->tail);
        return x;
    }
}
