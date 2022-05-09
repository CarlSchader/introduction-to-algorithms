#include<iostream>
#include"linked-list.h"

bool prompt(string& command, string& input) {
    cout << "command: ";
    cin >> command;
    cout << "\nvalue: ";
    cin >> input;
    cout << "\n";
    return true;
}

int main() {
    DoublyLinkedList<string> l = DoublyLinkedList<string>();

    cout << "commands: search, insert, remove\n";

    string command, input;
    while (prompt(command, input)) {
        try {
            if (command == "search") {
                DoublyLinkedList<string> *node = l.search(input);
                string exists = "false";
                if (node != nullptr)
                    exists = "true";
                cout << "exists: " << exists << endl;
            } else if (command == "insert") {
                l.insert(input);
            } else if (command == "remove") {
                l.remove(input);
            } else if (command == "remove-node") {
                DoublyLinkedList<string> *node = l.search(input);
                l.remove(node);
            } else {
                cout << "invalid command\n";
            }
            cout << l.toString();
            cout << endl;
        } catch (string e) {
            cout << e << endl;
        }
    }
}