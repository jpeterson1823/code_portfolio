#include "Tree.hpp"
#include <iostream>

Tree::Tree() {
    root = NULL;
}

Tree::~Tree() {
    destroyTree();
}

void Tree::destroyTree() {
    destroyTree(root);
}

void Tree::destroyTree(node* leaf) {
    if (leaf != NULL) {
        destroyTree(leaf->left);
        destroyTree(leaf->right);
        delete leaf;
    }
}

void Tree::insert(int key) {
    if (root != NULL) 
        insert(key, root);
    else {
        root = new node;
        root->value = key;
        root->left = NULL;
        root->right = NULL;
    }
}

void Tree::insert(int key, node* leaf) {
    if (key < leaf->value) {
        if (leaf->left != NULL) 
            insert(key, leaf->left);
        else {
            leaf->left = new node;
            leaf->left->value = key;
            leaf->left->left = NULL;
            leaf->left->right = NULL;
        }
    }
    else if (key >= leaf->value) {
        if (leaf->right != NULL) 
            insert(key, leaf->right);
        else {
            leaf->right = new node;
            leaf->right->value = key;
            leaf->right->left = NULL;
            leaf->right->right = NULL;
        }

    }
}

void Tree::inorderPrint() {
    inorderPrint(root);
    std::cout << '\n';
}

void Tree::inorderPrint(node* leaf) {
    if (leaf != NULL) {
        inorderPrint(leaf->left);
        std::cout << leaf->value << ", ";
        inorderPrint(leaf->right);
    }
}

void Tree::preorderPrint() {
    preorderPrint(root);
    std::cout << '\n';
}

void Tree::preorderPrint(node* leaf) {
    if (leaf != NULL) {
        std::cout << leaf->value << ", ";
        inorderPrint(leaf->left);
        inorderPrint(leaf->right);
    }
}