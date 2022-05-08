#ifndef DEQUE_H
#define DEQUE_H

#include<string>

using namespace std;

template <typename T>
class Deque {
    private:
        T *array;
        T *left;
        T *right;
        int count;
        int size;
    public:
        Deque(int size) {
            array = new T[size];
            left = array + size - 1;
            right = array;
            count = 0;
            this->size = size;
        }

        void push(T x) {
            if (count == size) {
                throw string("error: deque overflow");
            }
            *right = x;
            if (++right == array + size) {
                right = array;
            }
            count++;
        }

        void pushLeft(T x) {
            if (count == size) {
                throw string("error: deque overflow");
            }
            *left = x;
            if (left == array) {
                left = array + size;
            }
            left--;
            count++;
        }

        T pop() {
            if (count == 0) {
                throw string("error: deque underflow");
            }
            if (right == array) {
                right = array + size;
            }
            right--;
            count--;
            return *right;
        }

        T popLeft() {
            if (count == 0) {
                throw string("error: deque underflow");
            }
            if (++left == array + size) {
                left = array;
            }
            count--;
            return *left;
        }

        string toString() {
            string str = string("");
            T *current = left + 1;
            if (current == array + size) {
                current = array;
            }
            for (int i = 0; i < count; i++) {
                str.append(*current);
                str.append(", ");
                
                current++;
                if (current == array + size) {
                    current = array;
                }
            }
            return str;
        }
};

#endif