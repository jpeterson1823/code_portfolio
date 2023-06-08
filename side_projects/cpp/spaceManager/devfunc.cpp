#include "devfunc.hpp"
#include <vector>
#include <filesystem>
#include <iostream>

namespace fsys = std::filesystem;

void vprintf(std::vector<fsys::path> vec) {
    for (fsys::path path : vec)
        std::cout << path.string() << '\n';
}