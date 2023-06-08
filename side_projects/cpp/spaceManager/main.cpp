#include "devfunc.hpp"
#include <vector>
#include <string>
#include <filesystem>
#include <iostream>
#include <math.h>

namespace fs = std::filesystem;

std::vector<fs::path> getDirContents(std::string dir);
std::uintmax_t getDirSize(std::string path);
double bytes2gigs(std::uintmax_t bytes);

bool DEVLOG = false;

int main()
{
    double docSize = (double)(getDirSize("\\Users") / (1024.0 * 1024 * 1024));
    std::cout << docSize << std::endl;
    return 0;
}


// Uses filesystem to recursively get all file 
std::vector<fs::path> getDirContents(std::string dir)
{
    std::vector<fs::path> contentPaths;

    for (const auto& file : fs::directory_iterator(dir))
        contentPaths.push_back(file.path());

    return contentPaths;
}

// Recursively calculates the size of a directory
std::uintmax_t getDirSize(std::string dir)
{
    // get directory contents
    std::vector<fs::path> contents = getDirContents(dir);

    // summate the sizes of the dir contents
    //  - use uintmax_t as it has a max value of 18,446,744,073,709,551,615.
    std::uintmax_t dirSize = 0ULL;
    try {
        for (fs::path path : contents)
        {
            if (fs::is_directory(path))
                dirSize += getDirSize(path.string());
            else
                dirSize += fs::file_size(path.string());
        }
    } catch (fs::filesystem_error& e) {
        std::cout << e.what() << '\n';
    }

    return dirSize;
}