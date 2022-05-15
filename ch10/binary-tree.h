#pragma once

#include<string>

struct BTreeNode {
    std::string key;
    BTreeNode *parent;
    BTreeNode *left;
    BTreeNode *right;
};

void BTreeInsert(BTreeNode *tree, BTreeNode *node);

void BTreePrint(BTreeNode *tree);

void BTreePrintIterative(BTreeNode *tree);
