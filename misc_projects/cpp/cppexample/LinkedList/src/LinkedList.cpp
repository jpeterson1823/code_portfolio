#include "LinkedList.hpp"

LinkedList::LinkedList() {
    length = 0;
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}

LinkedList::~LinkedList() {
    for (int i = length; i > 0; i--)
        remove(0);
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

bool LinkedList::isEmpty() const {
    return length == 0;
}

bool LinkedList::isFull() const {
    return length == MAX_LENGTH;
}

void LinkedList::select(unsigned int index) {
    first();
    for (int i = 0; i < index; i++)
        current = current->getNext();
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
            tail = node;
        }
        else {
            last();
            current->setNext(node);
            tail = current->getNext();
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
            std::cout << "asdf" << std::endl;
            first();
            n->setNext(head);
            head = n;
        }
        else {
            select(index - 1);
            n->setNext(current->getNext());
            current->setNext(n);
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
            // delete removed node
            delete n;
        }

        // otherwise, remove as normal
        else {
            // move to node before one to be removed
            select(index - 1);
            // save pointer for deletion
            Node* n = current->getNext();
            removed = n->getValue();

            // if removing final node, set tail to current node as there isnt
            // a node following the one being removed
            if (index == length - 1)
                tail = current;
            // otherwise, set current's next to n's next
            else
                current->setNext(n->getNext());

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

std::ostream& operator<< (std::ostream& os, const LinkedList& list) {
    Node* n = list.getFirst();

    os << "LinkedList {\n";
    for (int i = 0; i < list.getLength()-1; i++) {
        os << '\t' << *n << ",\n";
        n = n->getNext();
    }
    os << '\t' << *n << "\n}";
    return os;
}
