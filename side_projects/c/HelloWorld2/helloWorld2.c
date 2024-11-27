#include <stdio.h>

int main() {
    const char string[14] = "Hello World!\n\0";
    printf(string);

    return 0;
}