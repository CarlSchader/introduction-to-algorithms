#include<iostream>
#include<string>
#include"nary-tree.h"

using namespace Nary;

bool prompt(std::string& command, std::string& input, int& depth) {
    std::cout << "\ncommand: ";
    std::cin >> command;
    std::cout << "value: ";
    std::cin >> input;
    std::cout << "depth: ";
    std::cin >> depth;
    std::cout << "\n";
    return true;
}

int main() {
    srand(static_cast<unsigned int>(std::time(nullptr)));

    NNode<std::string> *tree = nullptr;

    std::cout << "commands: insert <val> <depth>\n";

    std::string command, input;
    int depth;
    while (prompt(command, input, depth)) {
        try {
            if (command == "insert") {
                NNode<std::string> *newNode = NNodeNew(input);
                newNode->key = input;
                if (tree == nullptr)
                    tree = newNode;
                else
                    NNodeInsert<std::string>(tree, newNode, depth);
            } else {
                std::cout << "invalid command\n";
            }
            NNodePrintIterative<std::string>(tree);
        } catch (std::string e) {
            std::cout << e << std::endl;
        }
    }
}