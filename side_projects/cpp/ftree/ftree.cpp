#include <iostream>
#include "ftree.hpp"
using namespace std;

Node::Node(string name) :name(name) {
    this->parent = nullptr;
    this->contents;     // initialize vector to contain nothing
}

Node::Node(string name, Node* parent) :name(name), parent(parent) {}

void Node::addItem(Node item) {
    this->contents.push_back(item);
}

Node* Node::getParent() {
    return this->parent;
}

string Node::getName() {
    return this->name;
}

vector<Node> Node::getContents() {
    return this->contents;
}