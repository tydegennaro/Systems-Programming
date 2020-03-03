//   CSC 399: Systems Programming

// Program Name: 
//   multsum.c

// Program Purpose:
//   Program will print which numbers are a multsum, given a range
//   `START` to `FINISH` and a number to `MOD` by.

// Author(s):
//   Kyle DeGennaro
//   Tyler DeGennaro
//   Joey Germain


#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

/* Method to check if parameters are integers.
 * Returns 0 if any of the parameters are not integers.
 * Otherwise, returns 1.
 */
int paramsAreInts(int argc, char *argv[]) {
	// Skip over the first arg, which is the program name. Iterate across remaining args.
	for (int i = 1; i < argc; i++) {
		// In each arg, iterate across the digits.
		for (int j = 0; j < strlen(argv[i]); j++) {
			// If it's the first character, ignore a negative sign
			if (j == 0 && argv[i][j] == '-') {
				continue;
			}

			// If the current character is not a digit, return 0
			if (!isdigit(argv[i][j])) {
				return 0;
			}
		}
	}
	// All args were numbers
	return 1;
}

// Usage message
char *USAGE = "Usage: ./multsum START STOP MOD\n";

int main(int argc, char *argv[]) {
	// Verify input
	if (argc != 4) {
		//printf("Wrong number of args\n");
		printf(USAGE);
		return 1;
	} else if (!(paramsAreInts(argc, argv))) {
		//printf("Args need to be integers\n");
		printf(USAGE);
		return 1;
	} else if (argv[3][0] == '-') {
		//printf("Arg 3 needs to be positive\n");
		printf(USAGE);
		return 1;
	}

	int start = abs(atoi(argv[1]));
	int stop = abs(atoi(argv[2]));
	int mod = abs(atoi(argv[3]));

	for (int i = start; i <= stop; i++) {
		int sum = 0;
		int product = 1;
		
		// Calculate sum and product of characters
		for (int c = i; c > 0; c /= 10) {
			sum += c % 10;
			product *= c % 10;
		}

		// If this is a multsum, print the number
		if (sum % mod == product % mod) {
			printf("%d\n", i);
		}
	}
}

