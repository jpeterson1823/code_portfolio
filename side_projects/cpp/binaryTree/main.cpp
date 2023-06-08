#include "Tree.hpp"

int main() {
    Tree* tree = new Tree();
    tree->insert(10);
    tree->insert(6);
    tree->insert(14);
    tree->insert(5);
    tree->insert(8);
    tree->insert(11);
    tree->insert(18);

    tree->preorderPrint();

    delete tree;

    return 0;
}