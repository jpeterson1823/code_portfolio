#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _decode(char* binarystr, size_t size, int step);
void decode(char* binarystr);

int main(int argc, char* argv[]) {
	// check args
	if (argc < 2) {
		printf("Usage: %s file_path\n", argv[0]);
		printf("       %s < file_path\n", argv[0]);
		exit(0);
	}

	for (int i = 1; i < argc; i++) {
		decode(argv[i]);
	}

	return 0;
}

void _decode(char* binarystr, size_t size, int step) {
    // create string to store block of 'bits' of length 'step'
    char str[step + 1];
    str[step] = 0;      // null terminator

    for (int i = 0; i < size; i += step) {
        // grab block of bits and store in str
        strncpy(str, &binarystr[i], step);
        // convert binary string into int and print as char
        printf("%c", (int)strtol(str, NULL, 2));
    }
    // print newline
    printf("\n");
}

void decode(char* binarystr) {
	int len = strlen(binarystr);
    short c;

	// determine if 7-bit or 8-bit ASCII
	if (len % 7 == 0) { 		// 7-bit ascii
		printf("7-bit ASCII found.\n");
        _decode(binarystr, len, 7);
	}
	else if (len % 8 == 0) { 	// 8-bit ascii
		printf("8-bit ASCII found.\n");
        _decode(binarystr, len, 8);
	}
	else
		printf("Data is not recognized as 7-bit or 8-bit ASCII.\n");
}
