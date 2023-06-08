#include <iostream>
#include <cstdio>

const char* g_VALID_INT_CHARS = "0123456789-";

void getString(char* buff);
bool findChar(char target, char* str);
bool isValidIntStr(const char* str);
int jatoi(const char* str);


int main() {
    // allocate memory on stack
    size_t buffSize = 1023;
    char aStr[buffSize];
    char bStr[buffSize];

    char test[5] = "1234";
    std::cout << isValidIntStr(test) << std::endl;

    // get number 'a' from user, store in aStr buffer.
    std::cout << "Please input two numbers:\n";
    std::cout << "a = ";
    getString(aStr);
    while (!isValidIntStr(aStr)) {
        std::cout << "Please provide a valid integer.\na = ";
        getString(aStr);
    }

    // get number 'b' from user, store in bStr buffer.
    std::cout << "b = ";
    getString(bStr);
    while (!isValidIntStr(aStr)) {
        std::cout << "Please provide a valid integer.\na = ";
        getString(aStr);
    }

    // convert to integer and print sum
    int a = jatoi(aStr);
    int b = jatoi(bStr);
    std::cout << a << " + " << b << " = " << a + b << std::endl;

    return 0;
}

// Reads input from console, stores in buff
void getString(char* buff) {
    std::cin >> buff;
}

// Returns true if char is found in provided string.
bool findChar(char target, char* str) {
    char* ptr = str;
    while (*ptr != '\0') {
        if (*ptr == target)
            return true;
        ptr++;
    }
    return false;
}

/* Determines if the given string is a valid string representation
 * of an integer.
 * Returns:
 *  - true:  string is a valid representation of an integer
 *  - false: string is not a valid representation of an integer
 */
bool isValidIntStr(const char* str) {
    // attempt to find invalid chars in string
    char* ptr  = (char*)str;
    while(*ptr != '\0') {
        if (!findChar(*ptr, (char*)g_VALID_INT_CHARS))
            return false;
        ptr++;
    }

    // make sure there are no leading zeros
    if (str[0] == '-') {
        if (str[1] == '0' || str[1] == '\0')
            return false;
    } else {
        if (str[0] == '0' || str[0] == '\0')
            return false;
    }
    
    return true;
}

// Converts string into integer
int jatoi(const char* str) {
    // Determine sign
    bool isNegative = str[0] == '-';

    // Start conversion
    char* ptr = (char*)str;
    if (isNegative)
        ptr++;

    int num = 0;
    while(*ptr != '\0') {
        // shift current digits in number to the left
        num *= 10;

        // convert ASCII char into it's integer representation
        int digit = *ptr - '0';

        // append digit to end of number
        num += digit;

        // increment string pointer
        ptr++;
    }

    // add negative if needed
    if (isNegative)
        num *= -1;

    return num;
}
