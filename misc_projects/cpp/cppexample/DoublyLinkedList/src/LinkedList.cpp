#include "LinkedList.hpp"

LinkedList::LinkedList() {
    length = 0;
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}

LinkedList::~LinkedList() {
    // remove starting from end
    for (int i = length; i >= 0; i--)
        remove(length-1);

    // remove starting from beginning
    //for(int i = length; i >= 0; i--)
    //    remove(0);
}

void LinkedList::first() {
    current = head;
}

void LinkedList::last() {
    current = tail;
}

void LinkedList::next() {
    current = current->getNext();
}

void LinkedList::prev() {
    current = current->getPrev();
}

// select starting from front of list
void LinkedList::fselect(unsigned int index) {
    first();
    for (int i = 0; i < index; i++)
        current = current->getNext();
}

// select starting from back of list
void LinkedList::bselect(unsigned int index) {
    last();
    for (int i = length-1; i >= index; i--)
        current = current->getPrev();
}

void LinkedList::select(unsigned int index) {
    int middle = length / 2;
    if (index <= middle)
        fselect(index);
    else
        bselect(index);
}

bool LinkedList::isEmpty() const {
    return length == 0;
}

bool LinkedList::isFull() const {
    return length == MAX_LENGTH;
}

Node* LinkedList::getFirst() const {
    return head;
}

Node* LinkedList::getLast() const {
    return tail;
}

Node* LinkedList::get(unsigned int index) {
    select(index);
    return current;
}

unsigned int LinkedList::getLength() const {
    return length;
}

void LinkedList::add(int value) {
    if (!isFull()) {
        Node* node = new Node(value);
        if (isEmpty()) {
            head = node;
            tail = head;
        } else {
            node->setPrev(tail);
            tail->setNext(node);
            tail = node;
        }
        length++;
    } 
}

void LinkedList::set(unsigned int index, int value) {
    select(index);
    current->setValue(value);
}

void LinkedList::insert(int value, unsigned int index) {
    if (!isFull() && index < length && index >= 0) {
        Node* n = new Node(value);
        if (index == 0) {
            n->setNext(head);
            head->setPrev(n);
            head = n;
        }
        else {
            select(index - 1);
            n->setNext(current->getNext());
            n->setPrev(current);
            current->setNext(n);
            n->getNext()->setPrev(n);
        }
        length++;
    }
}

int LinkedList::remove(unsigned int index) {
    int removed = 0;
    if (!isEmpty()) {
        // if only head remains, make sure to handel hanging pointers
        if (length == 1) {
            delete head;
            head = nullptr;
            tail = nullptr;
            current = nullptr;
        }

        // if removing head, shorter method
        else if (index == 0) {
            // save node for deletion
            Node* n = head;
            removed = n->getValue();
            // set head to next node
            head = head->getNext();
            head->setPrev(nullptr);
            // delete removed node
            delete n;
        }

        // if removing tail, shorter method
        else if (index == length - 1) {
            Node* n = tail;
            removed = n->getValue();
            tail = tail->getPrev();
            tail->setNext(nullptr);
            delete n;
        }

        // otherwise, remove as normal
        else {
            // move to node before one to be removed
            select(index - 1);
            // save pointer for deletion
            Node* n = current->getNext();
            removed = n->getValue();

            // remove node from list
            current->setNext(n->getNext());
            n->getNext()->setPrev(current);

            // delete removed node
            delete n;
        }
        // decrement length
        length--;
    }

    return removed;
}

std::string LinkedList::toString() {
    std::string s = "LinkedList{";
    first();
    for (int i = 0; i < length-1; i++) {
        s += current->toString() + ',';
        next();
    }
    s += current->toString() + '}';
    return s;
}

