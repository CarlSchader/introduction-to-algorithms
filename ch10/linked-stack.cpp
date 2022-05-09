#include<iostream>
#include<string>
#include"linked-list.h"

using namespace std;

template<typename T>
class SinglyLinkedStack {
    private:
        SinglyLinkedList<T> *linkedList;
    public:
        SinglyLinkedStack() {
            linkedList = new SinglyLinkedList<T>();
        }

        void push(T x) {
            linkedList->insert(x);
        }

        T pop() {
            if (linkedList->next == linkedList) {
                throw string("error: stack underflow");
            }
            T x = linkedList->next->key;
            linkedList->remove(x);
            return x;
        }

        string toString() {
            return linkedList->toString();
        }
};

bool prompt(string& command, string& input) {
    cout << "command: ";
    cin >> command;
    cout << "\nvalue: ";
    cin >> input;
    cout << "\n";
    return true;
}

int main() {
    SinglyLinkedStack<string> s = SinglyLinkedStack<string>();

    cout << "commands: push, pop\n";

    string command, input;
    while (prompt(command, input)) {
        try {
            if (command == "push") {
                s.push(input);
            } else if (command == "pop") {
                s.pop();
            } else {
                cout << "invalid command\n";
            }
            cout << s.toString();
            cout << endl;
        } catch (string e) {
            cout << e << endl;
        }
    }
}
