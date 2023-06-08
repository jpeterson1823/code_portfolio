#include <stdio.h>
#include <string.h>

// usage string
const char* USE_STR = "Usage: binhexcalc number\0";

int main(int argc, char* argv[]) {
	// check number arguments
	if (argc != 2) {
		printf("ERROR: incorrect arguments provided.\n");
		printf("%s\n", USE_STR);
		return 1;
	}
	else {
		// determine type
		char prefix[2];
		strncpy(prefix, argv[1], 2);

		// if hex, convert and print
		if (strcmp("0x", prefix) == 0) {
			printf("Hex: %s\n", argv[1]);
		}
	}

	return 0;
}
