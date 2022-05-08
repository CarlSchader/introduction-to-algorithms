#include<iostream>
#include<exception>
#include<string>
#include"deque.h"

using namespace std;

bool prompt(string& command, string& input) {
    cout << "command: ";
    cin >> command;
    cout << "\nvalue: ";
    cin >> input;
    cout << "\n";
    return true;
}

int main() {
    Deque<string> d = Deque<string>(10);

    cout << "example input:\npush hello\npop\n";

    string command, input;
    while (prompt(command, input)) {
        try {
            if (command == "push") {
                d.push(input);
            } else if (command == "push-left") {
                d.pushLeft(input);
            } else if (command == "pop") {
                d.pop();
            } else if (command == "pop-left") {
                d.popLeft();
            } else {
                cout << "invalid command\n";
            }
            cout << d.toString();
            cout << endl;
        } catch (string e) {
            cout << e << endl;
        }
    }
}