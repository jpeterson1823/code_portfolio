
#include "func.hpp"

int main() {
    HomeworkFile file = HomeworkFile("hwTestFile");

    file.writeln("############################################################");
    file.writeln("# Name: John Peterson");
    file.writeln("# Class: CYEN 131 004");
    file.writeln("# Date: " + file.getDateString());
    file.writeln("# Description: ");
    file.writeln("############################################################");
    file.create();

    return 0;
}