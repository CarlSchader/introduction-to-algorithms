#include<iostream>
#include<string>

using namespace std;

template<typename T>
struct Node {
    T key;
    Node *np;
};

template<typename T>
Node<T> *nodeSearch(Node<T> *head, T key) {
    if (head == nullptr) {
        return nullptr;
    }
    // head previous node is 0, so 0 xor next = next
    Node<T> *current = head;
    Node<T> *previous = nullptr;
    Node<T> *next = (Node<T> *)((uintptr_t)(current->np) ^ (uintptr_t)previous);
    while (next != nullptr) {
        if (current->key == key) {
            return current;
        } else {
            previous = current;
            current = next;
            next = (Node<T> *)((uintptr_t)(current->np) ^ (uintptr_t)previous);
        }
    }
    if (current->key == key) {
        return current;
    }
    return nullptr;
}

template<typename T>
void nodeInsert(Node<T> *head, T key) {
    // head previous node is 0, so 0 xor next = next
    Node<T> *current = head;
    Node<T> *previous = nullptr;
    Node<T> *next = (Node<T> *)((uintptr_t)(current->np) ^ (uintptr_t)previous);
    while (next != nullptr) {
        previous = current;
        current = next;
        next = (Node<T> *)((uintptr_t)(current->np) ^ (uintptr_t)previous);
    }
    Node<T> *newNode = new Node<T>;
    newNode->key = key;
    newNode->np = current;
    current->np = (Node<T> *)((uintptr_t)previous ^ (uintptr_t)newNode);
}

template<typename T>
Node<T> *nodeDelete(Node<T> *head, Node<T> *deleteNode) {
    if (head == nullptr) {
        return head;
    }
    // head previous node is 0, so 0 xor next = next
    Node<T> *current = head;
    Node<T> *previous = nullptr;
    Node<T> *next = (Node<T> *)((uintptr_t)(current->np) ^ (uintptr_t)previous);
    while (current != deleteNode) {
        previous = current;
        current = next;
        if (current == nullptr) {
            return head;
        }
        next = (Node<T> *)((uintptr_t)(current->np) ^ (uintptr_t)previous);
    }

    cout << "current: " << current->key << endl;

    if (previous != nullptr) {
        previous->np = (Node<T> *)((uintptr_t)((uintptr_t)deleteNode ^ (uintptr_t)previous->np) ^ ((uintptr_t)next));
    }
    if (next != nullptr) {
        next->np = (Node<T> *)((uintptr_t)((uintptr_t)deleteNode ^ (uintptr_t)next->np) ^ ((uintptr_t)previous));
    }

    delete deleteNode;

    if (next == nullptr && previous == nullptr) {
        return nullptr;   
    } else {
        return head;
    }
}

template<typename T>
string listToString(Node<T> *head) {
    string str = "";
    if (head == nullptr) {
        return str;
    }
    // head previous node is 0, so 0 xor next = next
    Node<T> *current = head;
    Node<T> *previous = nullptr;
    Node<T> *next = (Node<T> *)((uintptr_t)(current->np) ^ (uintptr_t)previous);
    while (true) {
        str.append(current->key);
        str.append("->");
        previous = current;
        current = next;
        if (current == nullptr)
            break;
        next = (Node<T> *)((uintptr_t)(current->np) ^ (uintptr_t)previous);
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

    cout << "commands: search, insert, remove\n";

    string command, input;
    while (prompt(command, input)) {
        try {
            if (command == "search") {
                if (nodeSearch(head, input) == nullptr) {
                    cout << "not found\n";
                } else {
                    cout << "found\n";
                }
            } else if (command == "insert") {
                if (head == nullptr) {
                    head = new Node<string>;
                    head->key = input;
                    head->np = nullptr;
                } else {
                    nodeInsert(head, input);
                }

            } else if (command == "remove") {
                Node<string> *delNode = nodeSearch(head, input);
                if (delNode != nullptr) {
                    head = nodeDelete(head, delNode);
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