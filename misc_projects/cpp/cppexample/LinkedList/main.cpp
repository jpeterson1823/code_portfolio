#include <iostream>
#include "LinkedList.hpp"

int main() {
    std::cout << "Creating list object... ";
    std::cout.flush();
    LinkedList l;
    std::cout << "DONE\n";

    std::cout << "Adding values to list... ";
    std::cout.flush();
    for (int i = 0; i < 5; i++)
        l.add(i);
    std::cout << "DONE\n";
    std::cout << l << ", lenth=" << l.getLength() << std::endl;

    std::cout << "Removing 3rd value from list... ";
    std::cout.flush();
    l.remove(2);
    std::cout << "DONE\n";
    std::cout << l << ", lenth=" << l.getLength() << std::endl;

    l.insert(23, 0);
    l.insert(32, 2);
    std::cout << l << ", lenth=" << l.getLength() << std::endl;

    l.set(0, 100);
    std::cout << l << ", lenth=" << l.getLength() << std::endl;
    return 0;
}
