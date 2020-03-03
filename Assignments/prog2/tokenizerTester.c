/*******
 * Christian Duncan
 *
 * TokenizerTester
 *   This program simply reads in a bunch of lines from stdin
 *   and calls the tokenizer functions to print out each token
 *   Lines cannot be longer than MAX_LINE_LENGTH
 ********/

#include "tokenizer.h"
#include <stdio.h>

#define MAX_LINE_LENGTH 200

int main(int argc, char* argv[]) {
  char line[MAX_LINE_LENGTH+1];

  while (fgets(line, MAX_LINE_LENGTH+1, stdin) != NULL) {
    // We have our current line
    startToken(line);
    aToken answer;
    answer = getNextToken();
    while (answer.type != EOL) {
      switch (answer.type) {
      case ERROR:
	// Error (for some reason)
	printf("Token: ERROR\n");
	break;
      case BASIC:
	// Regular token
	printf("Token:  BASIC: %s\n", answer.start);
	break;
      case SINGLE_QUOTE:
	printf("Token: SINGLE: %s\n", answer.start);
	break;
      case DOUBLE_QUOTE:
	printf("Token: DOUBLE: %s\n", answer.start);
	break;
      default:
	fprintf(stderr, "Programming Error: Unrecognized type returned!!!\n");
      }
      answer = getNextToken();
    }
  }

  // Everything ran smoothly
  return 0;
}
