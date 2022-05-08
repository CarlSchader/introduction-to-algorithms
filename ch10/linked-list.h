#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include<string>

using namespace std;

template<typename T>
class SinglyLinkedList {
    private:
        T key;
        SinglyLinkedList *next;
    public:
        SinglyLinkedList() {
            key = T();
            next = this;
        }

        SinglyLinkedList(T key) {
            this->key = key;
            next = this;
        }

        bool search(T key) {
            SinglyLinkedList *current = this->next;
            while (current != this && current->key != key)
                current = current->next;
            return current != this;
        }

        void insert(T key) {
            SinglyLinkedList *newHead = new SinglyLinkedList(key);
            newHead->next = this->next;
            this->next = newHead;
        }

        void remove(T key) {
            SinglyLinkedList *current = this->next;
            SinglyLinkedList *previous = this;
            while (current != this && current->key != key) {
                previous = current;
                current = current->next;
            }
            if (current != this) {
                previous->next = current->next;
                delete current;
            }
        }

        string toString() {
            SinglyLinkedList *current = this->next;
            string str = string("");
            while (current != this) {
                str.append(current->key);
                str.append("->");
                current = current->next;
            }
            return str;
        }
};

#endif