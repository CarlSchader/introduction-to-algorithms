#include"queue.h"
#include<stdexcept>

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
        throw runtime_error("Error: queue overflow");
    } else {
        *s->tail = x;
        ++(s->tail);
    }
}

void *dequeue(queue *s) {
    if (s->tail == s->array) {
        throw runtime_error("Error: queue underflow");
        return NULL;
    } else {
        void *x = *s->tail;
        --(s->tail);
        return x;
    }
}
