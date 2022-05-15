#include"binary-tree.h"
#include"linked-list.h"
#include<iostream>

using namespace std;

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

void BTreeInsert(BTreeNode *tree, BTreeNode *node) {
    if (node->key <= tree->key) {
        if (tree->left == nullptr) {
            node->parent = tree;
            tree->left = node;
        } else {
            BTreeInsert(tree->left, node);
        }
    } else {
        if (tree->right == nullptr) {
            node->parent = tree;
            tree->right = node;
        } else {
            BTreeInsert(tree->right, node);
        }
    }
}

void BTreePrint(BTreeNode *tree) {
    if (tree == nullptr)
        return;
    BTreePrint(tree->left);
    cout << tree->key << endl;
    BTreePrint(tree->right);
}

void BTreePrintIterative(BTreeNode *tree) {
    SinglyLinkedStack<BTreeNode *> stack;
    BTreeNode *prev = nullptr;
    stack.push(tree);
    while (stack.size > 0) {
        tree = stack.pop();
        if (prev != tree->parent) {
            cout << tree->key << endl;
            prev = tree;
            continue;
        }
        if (tree->right != nullptr)
            stack.push(tree->right);
        stack.push(tree);
        if (tree->left != nullptr)
            stack.push(tree->left);
        prev = tree;
    }
}

void BTreePrintNoStack(BTreeNode *node) {
    BTreeNode *prev = node;
    BTreeNode *next;
    while (node != nullptr) {
        if (node->right == prev) {
            next = node->parent;
        } else if (node->left == prev) {
            cout << node->key << endl;
            if (node->right == nullptr) {
                next = node->parent;
            } else {
                next = node->right;
            }
        } else {
            if (node->left != nullptr) {
                next = node->left;
            } else if (node->right != nullptr) {
                cout << node->key << endl;
                next = node->right;
            } else {
                cout << node->key << endl;
                next = node->parent;
            }
        }
        prev = node;
        node = next;
    }        
}