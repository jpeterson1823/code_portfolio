#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

int main() {
    std::cout << fs::is_directory("..\\..\\..\\..\\..\\latech") << std::endl;
    return 0;
}