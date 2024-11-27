#include <stdio.h>

int main(int argc, char* argv[]) {
    // check argument count to see if an argument was provided
    if (argc < 2)
        printf("No arguments were provided.\n");
    
    else {
        printf("%i arguments proveded:\n", argc - 1);

        // better to use format string with using printf. Formats it into a string literal (safer)
        // loop through all extra arguments
        for (int i = 1; i < argc; i++)
            printf("\t%s\n", argv[i]);
    }
}