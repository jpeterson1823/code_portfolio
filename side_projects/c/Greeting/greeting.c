#include <stdio.h>
#include <stdlib.h>

// PROTOTYPES
int  mystrlen(char* str);
void mystrcat(char* cat, char* str1, char* str2);

// Define welcome message
char welcome[] = "Welcome, ";

int main(int argc, char* argv[]) {
    // check arguments
    if (argc < 2) {
        printf("%s\n", "Please provide a name argument.");
        return 1;
    }

    // allocate memory for greeting
    char* greeting = malloc(mystrlen(welcome) + mystrlen(argv[1]) + 1);

    // concatinate string and store in allocated memory
    mystrcat(greeting, welcome, argv[1]);

    // print the greeting
    printf("%s\n", greeting);

    // free the allocated memory
    free(greeting);

    return 0;
}

// My version of the strlen function
int mystrlen(char* str) {
    int len = 0;
    // loop until null char
    while (*(str + len) != '\0')
        len++;
    return len;
}

// My version of the strcat function
void mystrcat(char* cat, char* str1, char* str2) {
    int j = 0;
    for (int i = 0; i < mystrlen(str1); i++, j++)
        cat[j] = str1[i];

    for (int i = 0; i < mystrlen(str2); i++, j++)
        cat[j] = str2[i];

    cat[j+1] = '\0';
}

/*void mystrcat_while(char* cat, char* str1, char* str2) {
    // concatinated str index
    int c = 0;

    // str index counter
    int i = 0;

    // loop until null char
    while (str1[i] != '\0')
        cat[c++] = str1[i++];

    // reset index counter
    i = 0;

    // loop until null char
    while (str2[i] != '\0')
        cat[c++] = str2[i++];

    // add null terminator
    cat[c + 1] = '\0';
}*/