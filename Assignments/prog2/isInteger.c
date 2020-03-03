/**********************************
 * IsInteger
 * Author: Christian Duncan
 * For: Systems Programming
 *
 * Takes a list of arguments on the command line
 * and prints out which ones are valid integers and which are not.
 **********************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*********
 * printUsage: 
 *    Print Usage information and exit
 *********/
void printUsage(char* cmd) {
  fprintf(stderr, "Usage: %s ARG1 ... ARGN\n", cmd);
  exit(1);
}


int main(int argc, char** argv) {
  if (argc < 2) {
    printUsage(argv[0]);
  }

  // Checks each argument given and whether it is a valid number or not
  int i;
  for (i = 1; i < argc; i++) {
    char *endptr;  // Endptr points to first character NOT matched
    long int num = strtol(argv[i], &endptr, 10);
    if (*endptr == '\0') {
      // The last character is the end of the string... so no illegal character
      //   Caution: Assumes that the original string (argv[1] is not empty)
      //   Otherwise a string of "\0" would be considered valid.
      printf("Argument %d (%s) is a valid number: %ld\n",
	     i, argv[i], num);
    } else {
      printf("Argument %d (%s) is invalid.  Illegal character: %c\n",
	     i, argv[i], *endptr);
    }
  }

  return 0;
}
