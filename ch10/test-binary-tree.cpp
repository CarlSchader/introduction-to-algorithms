#include<iostream>
#include<string>
#include"binary-tree.h"

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
    BTreeNode *tree = nullptr;

    cout << "commands: insert <val>\n";

    string command, input;
    int address;
    while (prompt(command, input)) {
        try {
            if (command == "insert") {
                BTreeNode *newNode = new BTreeNode;
                newNode->key = input;
                if (tree == nullptr)
                    tree = newNode;
                else
                    BTreeInsert(tree, newNode);
            } else {
                cout << "invalid command\n";
            }
            BTreePrintNoStack(tree);
        } catch (string e) {
            cout << e << endl;
        }
    }
}