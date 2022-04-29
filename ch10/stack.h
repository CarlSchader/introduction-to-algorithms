#ifndef STACK_H
#define STACK_H

struct stack {
    void** array;
    void** tail;
    int size;
};

stack *newStack(int size);

void push(stack *s, void *x);

void *pop(stack *s);

#endif