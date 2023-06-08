#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// CONSTANTS
const string CMDS = "+-<>[].,";

// PROTOTYPES
string read_file(string path);
string bf_format(string raw);

// main function
int main(int argc, char** argv) {
    // if a file is not provided or too many arguments given
    if (argc != 2) {
        printf("Error: incorrect number of arguments provided.\nUsage: bfcompile path/to/file");
        return 1;
    }
    
    printf("Compiling file: %s\n", argv[1]);

    // get formatted bf code
    string filedata = read_file(argv[1]);
    printf("Raw Data: %s\n", filedata);
    
    return 0;
}


// reads a brainfuck file and returns its string representation
string read_file(string path) {
    // create file obj and data string
    ifstream filestream (path);
    string data;

    // if file is successfully opened, write data to string
    if (filestream.is_open()) {
        string line;
        while (getline(filestream, line)) data += line;
        filestream.close();
    }
    else {
        printf("Failed to open file %s", path);
        return NULL;
    }

    // return this data
    return data;
}


// formats given raw file data to brainfuck command syntax
string bf_format(string raw) {
    // create command string to be returned
    string bf;

    // iterate through raw data and keep recognized chars only
    for (char c : raw) {
        // if character in recognized char list, add to bf string
        if (CMDS.find_first_of(c) != -1)
            bf += c;
    }

    // return the formatted string
    return bf;
}