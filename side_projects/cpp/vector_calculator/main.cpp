#include <iostream>
#include <vector>
#include "vectors.hpp"

const std::string CMD_PROMPT = "VecCalc >$ ";
const std::vector<std::string> VALID_COMMANDS = {
    "new",
    "exit"
};

void greet();
std::string getCmd(std::string msg = CMD_PROMPT);
double getNumber(char component);




int main() {
    greet();

    std::vector<vec2> vec2List;
    bool shouldExit = false;
    std::string cmd;

    while (!shouldExit) {
        cmd = getCmd();

        if (cmd.compare(VALID_COMMANDS[0])) {

        }
    }

    return 0;
}




void greet() {
    std::cout << "##### VecCalc v0.0.1 #####\n";
    std::cout << "Valid commands:\n";
    for (std::string cmd : VALID_COMMANDS)
        std::cout << cmd << '\n';
    std::cout << std::endl;
}

std::string getCmd(std::string msg) {
    std::string input;
    while (true) {
        std::cout << msg;
        std::cin >> input;
        for (int i = 0; i < VALID_COMMANDS.size(); i++)
            if (VALID_COMMANDS[i].compare(input) == 0)
                return input;
        std::cout << "Unrecognized command: \"" << input << "\"\n Please try again." << std::endl;
    }
    return input;
}
