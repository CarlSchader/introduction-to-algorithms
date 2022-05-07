#ifndef DEQUE_H
#define DEQUE_H


template <typename T>
class Deque {
    private:
        T *array;
        T *head;
        T *tail;
        int size;
    public:
        Deque(int size) {
            array = new T[size];
            head = array - 1;
            tail = array;
        }
};

#endif