#include<iostream>
#include<string>
// #include"linked-list.h"

using namespace std;

template<typename T>
struct Node {
    T key;
    Node *next;
};

template<typename T>
void insert(Node<T> *head, Node<T> *prev, Node<T> *n) {
    prev->next = n;
    n->next = head;
}

template<typename T>
void remove(Node<T> *prev, Node<T> *n) {
    prev->next = n->next;
    delete n;
}

template<typename T>
string listToString(Node<T> *l) {
    if (l == nullptr) {
        return "";
    }

    Node<T> *cur = l->next;
    string str = l->key;
    str.append("->");
    while (cur != l) {
        str.append(cur->key);
        str.append("->");
        cur = cur->next;
    }
    return str;
}

bool prompt(string& command, string& input) {
    cout << "command: ";
    cin >> command;
    cout << "\nvalue: ";
    cin >> input;
    cout << "\n";
    return true;
}

int main() {
    Node<string> *head = nullptr;
    Node<string> *tail = nullptr;

    cout << "commands: search, insert, remove\n";

    string command, input;
    while (prompt(command, input)) {
        try {
            if (command == "search") {
                // cout << "exists: " << l.search(input) << endl;
            } else if (command == "insert") {
                if (tail == nullptr) {
                    tail = new Node<string>;
                    tail->key = input;
                    tail->next = tail;
                    head = tail;
                } else {
                    tail->next = new Node<string>;
                    tail = tail->next;
                    tail->key = input;
                    tail->next = head;
                }
            } else if (command == "remove") {
                if (tail == nullptr) {
                    throw string("error: stack underflow");
                } else if (head == tail) {
                    tail = nullptr;
                    delete head;
                    head = tail;
                } else {
                    Node<string> *prev = head;
                    head = head->next;
                    tail->next = head;
                    delete prev;
                }
            } else {
                cout << "invalid command\n";
            }
            cout << listToString(head);
            cout << endl;
        } catch (string e) {
            cout << e << endl;
        }
    }
}