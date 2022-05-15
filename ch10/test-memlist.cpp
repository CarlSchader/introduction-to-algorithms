#include<iostream>
#include<string>
#include"memlist.h"

using namespace std;

bool prompt(string& command, string& input) {
    cout << "\ncommand: ";
    cin >> command;
    cout << "value: ";
    cin >> input;
    cout << "\n";
    return true;
}

int main() {
    Memlist mem = Memlist(5);

    cout << "commands: alloc <val>, free <address>, compactify <anything>\n";

    string command, input;
    int address;
    while (prompt(command, input)) {
        try {
            if (command == "alloc") {
                address = mem.alloc();
                mem.set(address, stoi(input));
            } else if (command == "free") {
                mem.free(stoi(input));
            } else if (command == "compactify") {
                mem.compactify();
            } else {
                cout << "invalid command\n";
            }
            cout << "free: " + mem.freeString() << endl;
            cout << "alloc: " + mem.allocString() << endl;
        } catch (string e) {
            cout << e << endl;
        }
    }
}