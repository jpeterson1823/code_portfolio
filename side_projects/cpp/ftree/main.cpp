#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include "ftree.hpp"
namespace fs = std::filesystem;

fs::path rmDotSlash(fs::path ogPath);

int main()
{
    std::vector<fs::path> paths;
    for (const auto & entry : fs::directory_iterator("./"))
        paths.push_back(entry);

    for (fs::path path : paths)
        std::cout << rmDotSlash(path) << std::endl;

    return 0;
}

fs::path rmDotSlash(fs::path ogPath) {
    std::string str = "";
    std::string ogPathStr = ogPath.string();
    for (int i = 2; i < ogPathStr.length(); i++) {
        str += ogPathStr[i];
    }
    return (fs::path)str;
}