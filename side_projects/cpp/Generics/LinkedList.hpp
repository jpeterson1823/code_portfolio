#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class Node {
    // member vars
    private:
        T data;
        Node<T>* next;
    
    // public methods
    public:
        Node<T>();
        ~Node<T>();
        T getData();
        Node<T>* getNext();
        void setData(T data);
        void setNext(Node<T>* next);
};

template <class T>
class LinkedList {
    // member vars
    private:
        int numElements;
        Node<T>* head;
        Node<T>* tail;
        Node<T>* current;
    
    // member methods
    private:
        bool moveTo(int index);
        bool isEmpty();
        bool isFull();

    
    // public methods
    public:
        // constructor & destructor
        LinkedList<T>();
        ~LinkedList<T>();

        // iterative helpers
        void first();
        void next();
        void last();

        // other
        int size();
        void add(T element);
        void set(int index, T element);
        T getFirst();
        T getLast();
        T get(int index);
        T remove(int index);
};




// ------------ DEFINITIONS ------------




// Node Constructor
template <class T>
Node<T>::Node() {
    data = 0;
    next = (Node<T>*)malloc(sizeof(Node<T>));
}

// Node Destructor
template <class T>
Node<T>::~Node() {
    if (next) delete next;
}

// Node.data Accessor
template <class T>
T Node<T>::getData() { return data; }

// Node.data Mutator
template <class T>
void Node<T>::setData(T data) { this->data = data; }

// Node.next Accessor
template <class T>
Node<T>* Node<T>::getNext() { return next; }

// Node.next Mutator
template <class T>
void Node<T>::setNext(Node<T>* next) { this->next = next; }




// LinkedList Constructor
template <class T>
LinkedList<T>::LinkedList() {
    int numElements = 0;
    head = new Node<T>();
    tail = new Node<T>();
    current = new Node<T>();
}

// LinkedList Destructor
template <class T>
LinkedList<T>::~LinkedList() {
    if (head) delete head;
    if (tail) delete tail;
    if (current) delete current;
}

// LinkedList: returns true if list is empty, false otherwise
template <class T>
bool LinkedList<T>::isEmpty() { return numElements == 0; }

// LinkedList: returns the number of elements in the list
template <class T>
int LinkedList<T>::size() { return numElements; }

// LinkedList: sets current to head
template <class T>
void LinkedList<T>::first() { current = head; }

// LinkedList: sets current to next node
template <class T>
void LinkedList<T>::next() { current = current->getNext(); }

// LinkedList: moves current pointer to specified index
template <class T>
bool LinkedList<T>::moveTo(int index) {
    // check if empty and if index within range
    if (!isEmpty() && index >= 0 && index < numElements) {
        // set current pointer to first, then move to index
        first();
        for (int i = 0; i < index; i++)
            next();
        return true;
    }
    else return false;
}

// LinkedList: adds element to the end of list
template <class T>
void LinkedList<T>::add(T element) {
    // dynamically create new node
    Node<T>* node = new Node<T>();
    node->setData(element);
    node->setNext(nullptr);

    if (isEmpty()) {
        head = node;
        current = head;
        tail = head;
    }
    else {
        tail->setNext(node);
        tail = node;
    }

    // increment numElements
    numElements++;
}

// LinkedList: gets element at specified index
template <class T>
T LinkedList<T>::get(int index) {
    if (moveTo(index))
        return current->getData();
    // otherwise, error out
    else return -1;
}

// LinkedList: sets element at specific index to specified value
template <class T>
void LinkedList<T>::set(int index, T element) {
    // check if noe empty and that index is within range
    if (!isEmpty() && index >=0 && index < numElements) {

    }
}

#endif