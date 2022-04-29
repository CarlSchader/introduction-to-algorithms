#ifndef QUEUE_H
#define QUEUE_H

struct queue {
    void** array;
    void** head;
    void** tail;
    int size;
};

queue *newQueue(int size);

void enqueue(queue *s, void *x);

void *dequeue(queue *s);

#endif