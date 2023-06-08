#include "Node.hpp"

Node::Node(int value, Node* next) : value(value), next(next) { }
Node::Node(int value) : Node(value, nullptr) { }
Node::Node() : Node(0, nullptr) { }

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

std::string Node::toString() const {
    std::string s = "Node{value=";
    s += std::to_string(value);
    s += "}";
    return s;
}

std::ostream& operator<<(std::ostream& os, Node& node) {
    os << node.toString();
    return os;
}