#pragma once
#include <iostream>
#include <string>

class Node {
private:
    int value;
    Node* next;

public:
    Node();
    Node(int value);
    Node(int value, Node* next);

    int getValue() const;
    void setValue(int value);

    Node* getNext() const;
    void setNext(Node* node);

    std::string toString() const;

    friend std::ostream& operator<<(std::ostream& os, Node& node);
};