#include"queue.h"

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
    void **original = s->head + 1;
    if (s->tail - s->array == s->size) {
        s->tail = s->array;
    }
    if (s->tail == s->head) {
        throw "Error: queue overflow";
    } else {
        *s->tail = x;
        s->tail++;
    }
}

void *dequeue(queue *s) {
    void **original = s->head;
    s->head++;
    if (s->head - s->array == s->size) {
        s->head = s->array;
    }
    if (s->head == s->tail) {
        s->head = original;
        throw "Error: queue underflow";
    } else {
        return *s->head;
    }
}
