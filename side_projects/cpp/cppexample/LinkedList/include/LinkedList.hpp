#include "Node.hpp"

class LinkedList {
private:
    const unsigned int MAX_LENGTH = 0xFFFFFFFF;
    Node* head;
    Node* tail;
    Node* current;
    unsigned int length;

private:
    void first();
    void last();
    void next();
    void select(unsigned int index);

public:
    LinkedList();
    ~LinkedList();

    bool isEmpty() const;
    bool isFull() const;
    Node* getFirst() const;
    Node* getLast() const;
    Node* get(unsigned int index);
    unsigned int getLength() const;

    void add(int value);
    void set(unsigned int index, int value);
    void insert(int value, unsigned int index);
    int remove(unsigned int index);

    std::string toString();
    friend std::ostream& operator<< (std::ostream& os, const LinkedList& list);
};