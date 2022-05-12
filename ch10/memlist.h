#pragma once

#include<string>

using namespace std;

class Memlist {
    private:
        int size;
        int freeHead;
        int allocHead;
        int *heap;
    public:
        Memlist(int size);
        int alloc();
        void free(int address);
        void set(int address, int val);
        string freeString();
        string allocString();
};