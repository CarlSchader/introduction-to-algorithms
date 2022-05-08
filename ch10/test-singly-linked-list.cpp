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
    SinglyLinkedList<string> l = SinglyLinkedList<string>();

    cout << "commands: search, insert, remove\n";

    string command, input;
    while (prompt(command, input)) {
        try {
            if (command == "search") {
                cout << "exists: " << l.search(input) << endl;
            } else if (command == "insert") {
                l.insert(input);
            } else if (command == "remove") {
                l.remove(input);
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