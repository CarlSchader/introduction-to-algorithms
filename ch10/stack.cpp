#include"stack.h"

using namespace std;

stack *newStack(int size) {
    stack *s = new stack();
    s->array = new void *[size];
    s->tail = s->array;
    s->size = size;
    return s;
}

void push(stack *s, void *x) {
    if (s->tail - s->array == s->size) {
        throw "Error: stack overflow";
    } else {
        *s->tail = x;
        ++(s->tail);
    }
}

void *pop(stack *s) {
    if (s->tail == s->array) {
        throw "Error: stack underflow";
    } else {
        void *x = *s->tail;
        --(s->tail);
        return x;
    }
}
