#ifndef QUEUE_H
#define QUEUE_H

struct queue {
    void** array;
    void** head;
    void** tail;
    int size;
    int count;
};

queue *newQueue(int size);

void enqueue(queue *s, void *x);

void *dequeue(queue *s);

void toString(queue *s, char *buffer);

#endif