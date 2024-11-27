#include "Node.hpp"

Node::Node(int value, Node* next, Node* prev) : value(value), next(next), prev(prev) { }
Node::Node(int value, Node* next) : Node(value, next, nullptr) { }
Node::Node(int value) : Node(value, nullptr, nullptr) { }

int Node::getValue() const {
    return value;
}

void Node::setValue(int value) {
    this->value = value;
}

Node* Node::getNext() const {
    return next;
}

void Node::setNext(Node* node) {
    next = node;
}


Node* Node::getPrev() const {
    return prev;
}


void Node::setPrev(Node* node) {
    prev = node;
}


std::string Node::toString() const {
    std::string s = "Node{value=";
    s += std::to_string(value);
    s += "}";
    return s;
}
