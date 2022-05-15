#include"memlist.h"
#include<string>
#include<iostream>

using namespace std;

Memlist::Memlist(int size) {
    this->size = size;
    heap = new int[size * 3];
    freeHead = 0;
    allocHead = -1;
    for (int i = 0; i < size; i++) {
        heap[(i * 3) + 1] = 3 * (i + 1);
    }
    heap[((size - 1) * 3) + 1] = -1;
}

int Memlist::alloc() {
    if (freeHead == -1) {
        throw string("stack overflow");
    }
    int nextAlloc = freeHead;
    freeHead = heap[freeHead + 1];
    heap[nextAlloc + 1] = allocHead;
    heap[allocHead] = nextAlloc;
    allocHead = nextAlloc;
    return allocHead;
}

void Memlist::free(int address) {
    int next = heap[address + 1];
    int prev = heap[address];

    if (address == allocHead) {
        int nextAllocHead = heap[allocHead + 1];
        heap[address + 1] = freeHead;
        allocHead = nextAllocHead;
        freeHead = address;
        heap[allocHead] = -1;
    } else {
        if (next != -1) {
            heap[next] = prev;
        }
        if (prev != -1) {
            heap[prev + 1] = next;
        }
        heap[address + 1] = freeHead;
        freeHead = address;
    }

}

void Memlist::set(int address, int val) {
    heap[address + 2] = val;
}

void Memlist::compactify() {
    int index = 0;
    int current = allocHead;
    while (current != -1) {
        int next = heap[current + 1];
        int val = heap[current + 2];

        if (next == index) {
            next = current;
            heap[current + 1] = heap[index + 1];
            heap[current + 2] = heap[index + 2];
            heap[index + 1] = index + 3;
            heap[index + 2] = val;
        } else {
            heap[current + 1] = heap[index + 1];
            heap[current + 2] = heap[index + 2];
            heap[index + 1] = index + 3;
            heap[index + 2] = val;  
        }

        // set next current
        current = next;
        index += 3;
    }
    heap[(index - 3) + 1] = -1;
    
    if (allocHead != -1)
        allocHead = 0;
    freeHead = index;

    current = heap[allocHead + 1];
    int previous = allocHead;
    while (current != -1) {
        heap[current] = previous;
        previous = current;
        current = heap[current + 1];
    }
    
    while (index < (size - 1) * 3) {
        heap[index + 1] = index + 3;
        index += 3;
    }
    heap[index + 1] = -1;
}

string Memlist::freeString() {
    string str = "";
    int current = freeHead;
    while (current != -1) {
        str.append(to_string(current));
        str.append("->");
        current = heap[current + 1];
    }
    return str;
}

string Memlist::allocString() {
    string str = "";
    int current = allocHead;
    while (current != -1) {
        str.append(to_string(current));
        str.append(",");
        str.append(to_string(heap[current + 2]));
        str.append("<->");
        current = heap[current + 1];
        // cout << current << endl;
    }
    return str;
}