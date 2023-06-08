#include <iostream>
#include "LinkedList.hpp"

int main(int argc, char* argv[]) {
    LinkedList<int> l;
    std::cout << "Created Linked List\n";

    l.add(1);
    std::cout << "Added element to list\n";

    int size = l.size();
    std::cout << "List size: " << size << "\n";

    int data = l.get(0);
    std::cout << "Data : " << data << "\n";

    return 0;
}