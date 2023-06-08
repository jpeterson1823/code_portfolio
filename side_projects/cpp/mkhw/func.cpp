#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "func.hpp"

using namespace std;

HomeworkFile::HomeworkFile(string fileName) : fileName(fileName) {
    this->fileName += ".py";
    cout << "Creating homework file object: " << fileName << endl;
    fileText = "";


    // Check to see if a file with provided name already exists to prevent overwritting.
    ifstream f(fileName);
    if (f.good()) {
        string response;
        cout << "A file with the name '" << fileName << "already exists. Continuing will overwrite its contents\n Do you still wish to continue?(Y/N) ";
        cin >> response;

        if (response == "N") {
            cout << "\nExiting program...\n";
            exit(0);
        }
        else if (response == "Y") {
            cout << "\nContinuing to create file object: " << fileName << "...\n";
        }
        else {
            cout << "Invalid response: \'" << response << "\' not a valid option.\n Exiting...\n";
            exit(1);
        }
    }
}

string HomeworkFile::getName() {
    return HomeworkFile::fileName;
}

void HomeworkFile::write(string text) {
    fileText += text;
}

void HomeworkFile::writeln(string text) {
    write(text + '\n');
}

void HomeworkFile::create() {
    cout << "Writing changes to file " << fileName << "...\n";
    ofstream fileStream;
    fileStream.open(fileName);
    fileStream << fileText;
    fileStream.close();
    cout << "Successfully wrote data to file.\n";
}

string HomeworkFile::getDateString() {
    auto t = time(nullptr);
    auto tm = *localtime(&t);

    ostringstream oss;
    oss << put_time(&tm, "%m-%d-%Y");
    return oss.str();

}