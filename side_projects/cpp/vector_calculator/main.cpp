#include <iostream>
#include <map>
#include "vectors.hpp"

const std::string CMD_PROMPT = "VecCalc >$ ";

const unsigned short NUM_CMDS = 3;
const std::string VALID_CMDS[NUM_CMDS] = {
    "exit",
    "show",
    "new"
};

void greet();
std::string getCmd(std::string msg = CMD_PROMPT);
double getNumber(const char* msg);




int main() {
    greet();

    std::map<std::string, vec2> vec2map;
    std::string cmd;

    for (;;) {
        cmd = getCmd();

        // exit
        if (cmd.compare(VALID_CMDS[0]) == 0) {
            break;
        }

        // display variables
        else if (cmd.compare(VALID_CMDS[1]) == 0) {
            std::cout << "Stored Variables:\n";
            for (std::map<std::string, vec2>::iterator it = vec2map.begin(); it != vec2map.end(); ++it) {
                std::cout << it->first << " = " << it->second << '\n';
            }
            std::fflush(stdout);
        }

        // new
        else if (cmd.compare(VALID_CMDS[2]) == 0) {
            // get name of vec
            std::string name;
            std::cout << "Vec2 Name: ";
            std::cin >> name;

            double x = getNumber("x = ");
            double y = getNumber("y = ");
            vec2map[name] = vec2(x, y);
        }
    }

    return 0;
}




void greet() {
    std::cout << "##### VecCalc v0.0.1 #####\n";
    std::cout << "Valid commands:\n";
    for (std::string cmd : VALID_CMDS)
        std::cout << cmd << '\n';
    std::cout << std::endl;
}

std::string getCmd(std::string msg) {
    std::string input;
    while (true) {
        std::cout << msg;
        std::cin >> input;
        for (int i = 0; i < NUM_CMDS; i++)
            if (VALID_CMDS[i].compare(input) == 0)
                return input;
        std::cout << "Unrecognized command: \"" << input << "\"\n Please try again." << std::endl;
    }
    return input;
}

double getNumber(const char* msg="Number Input: ") {
    std::string input;
    double d;
    for (;;) {
        std::cout << msg;
        std::cin >> input;

        try {
            d = std::stod(input);
            break;
        }
        catch (std::invalid_argument e) {
            std::cout << "Please provide a valid number." << std::endl;
        }
    }
    return d;
}