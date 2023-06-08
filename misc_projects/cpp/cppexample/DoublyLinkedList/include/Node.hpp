#pragma once
#include <iostream>
#include <string>


class Node {
private:
    int value;
    Node* next;
    Node* prev;

public:
    Node(int value = 0);
    Node(int value, Node* next);
    Node(int value, Node* next, Node* prev);

    int getValue() const;
    void setValue(int value);

    Node* getNext() const;
    void setNext(Node* node);

    Node* getPrev() const;
    void setPrev(Node* node);

    std::string toString() const;
};
