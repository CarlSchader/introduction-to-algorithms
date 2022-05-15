#pragma once

#include<iostream>
#include"linked-list.h"

template<typename T>
class SinglyLinkedStack {
    private:
        SinglyLinkedList<T> *linkedList;
    public:
        int size;

        SinglyLinkedStack() {
            linkedList = new SinglyLinkedList<T>();
            size = 0;
        }

        void push(T x) {
            linkedList->insert(x);
            size++;
        }

        T pop() {
            if (linkedList->next == linkedList) {
                throw string("error: stack underflow");
            }
            T x = linkedList->next->key;
            linkedList->remove(x);
            size--;
            return x;
        }

        string toString() {
            return linkedList->toString();
        }
};

namespace Nary {
    template<typename T>
    struct NNode {
        T key;
        NNode<T> *parent;
        NNode<T> *child;
        NNode<T> *right;
    };

    template<typename T>
    NNode<T> *NNodeNew(T key) {
        NNode<T> *newNode = new NNode<T>;
        newNode->key = key;
        newNode->parent = nullptr;
        newNode->child = nullptr;
        newNode->right = nullptr;
        return newNode;
    }

    template<typename T>
    void NNodeInsert(NNode<T> *node, NNode<T> *newNode, int depth) {
        while (depth > 0 && node->child != nullptr) {
            node = node->child;
            depth--;
        }
        if (depth > 0) {
            newNode->parent = node;
            node->child = newNode;
        } else {
            newNode->parent = node->parent;
            newNode->right = node;
            newNode->parent->child = newNode;
        }
    }

    template<typename T>
    void NNodePrint(NNode<T> *node) {
        if (node == nullptr)
            return;
        std::cout << node->key << std::endl;
        
        NNode<T> *current = node->child;
        while (current != nullptr) {
            NNodePrint<T>(current);
            current = current->right;
        }
    }

    template<typename T>
    void NNodePrintIterative(NNode<T> *node) {
        while (node->child != nullptr) {
            node = node->child;
        }

        while (node != nullptr) {
            std::cout << node->key << std::endl;
            if (node->right != nullptr) {
                node = node->right;
            } else {
                if (node->parent->right != nullptr && 
                        node->parent->right->child != nullptr) {
                    node = node->parent->right->child;
                } else {
                    node = node->parent;
                }
            }
        }
    }
}