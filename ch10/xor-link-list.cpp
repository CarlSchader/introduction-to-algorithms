#include<iostream>
#include<string>

using namespace std;

template<typename T>
struct Node {
    T key;
    Node *np;
};

template<typename T>
Node<T> *nodeSearch(Node<T> head, T key) {
    // head previous node is 0, so 0 xor next = next
    Node<T> *current = head;
    Node<T> *previous = nullptr;
    Node<T> *next = current.np ^ previous;
    while (next != nullptr) {
        if (current->key == key) {
            return current;
        } else {
            previous = current;
            current = next;
            next = current.np ^ previous;
        }
    }
    return nullptr;
}

template<typename T>
void nodeInsert(Node<T> *head, T key) {
    if (head == nullptr) {
        Node<T> *newNode = new Node<T>;
        newNode->key = key;
        newNode->np = current;
        return;
    }
    // head previous node is 0, so 0 xor next = next
    Node<T> *current = head;
    Node<T> *previous = nullptr;
    Node<T> *next = current.np ^ previous;
    while (next != nullptr) {
        previous = current;
        current = next;
        next = current.np ^ previous;
    }
    Node<T> *newNode = new Node<T>;
    newNode->key = key;
    newNode->np = current;
    current.np = previous ^ newNode;
}

template<typename T>
void nodeDelete(Node<T> head, Node<T> *deleteNode) {
    // head previous node is 0, so 0 xor next = next
    Node<T> *current = head;
    Node<T> *previous = nullptr;
    Node<T> *previous2 = nullptr;
    Node<T> *next = current.np ^ previous;
    while (current != deleteNode) {
        previous2 = previous;
        previous = current;
        current = next;
        if (current == nullptr) {
            return;
        }
        next = current.np ^ previous;
    }
    if (previous != nullptr) {
        previous.np = previous2 ^ next;
    }
    if (next != nullptr) {
        Node<T> *next2 = next.np ^ current;
        next.np = previous ^ next2;
    }
    delete deleteNode;
}

template<typename T>
string listToString(Node<T> *head) {
    string str = "";
    // head previous node is 0, so 0 xor next = next
    Node<T> *current = head;
    Node<T> *previous = nullptr;
    Node<T> *next = current.np ^ previous;
    while (current != nullptr) {
        str.append(current->key);
        str.append("->");
        previous = current;
        current = next;
        next = current.np ^ previous;
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