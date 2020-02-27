/******
 * Authors: YOUR NAME (it is - or will be - your code)
 * Tokenizer:
 *    This collection of functions takes as input a single line of text
 *    and tokenizes that text.  Each call to getNextToken() returns the
 *    next token (as a string) in the line.  If the line is complete a 
 *    NULL is returned.
 *
 * See Tokenizer.h for details...
 *******/
#include "tokenizer.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Pointer
static char *lineCopy = NULL; // Copy of the line to process
static char *position; // Position in the line

void startToken(char* line) {
  if (line == NULL) {
    // Hey, no line even passed
    fprintf(stderr, "ERROR: Null line given.  Using empty line.\n");
    line = "";
  }


  // Allocate space for and make a copy of the line (so we have it safely)
  int length = strlen(line);
  // Type cast to pointer char
  // Length + 1 here because strlen Does not count 
  // the '/0' byte at the end of the string
  // When in doubt, add an extra byte
  lineCopy = (char*) realloc(lineCopy, (length+1) * sizeof(char));
  strcpy(lineCopy, line);

  // Start the token pointing to the first position
  position = lineCopy;
}

// Find first non white space, then scan across to the end

aToken getNextToken() {
  aToken res;

  // Find and process the next token...
  while (isspace(*position)) position++;
  res.start = position;
  if (*position == 0)
  {
    // At end of string, return EOL
    res.start = NULL;
    res.type = EOL;
  } 
  else if (*position == '\"') {
    position++;
    res.type = DOUBLE_QUOTE;
    res.start = position;
    while (*position != '\"') position++;
    *position = 0;
  }
  else if (*position == '\'') {
    position++;
    res.type = SINGLE_QUOTE;
    res.start = position;
    while (*position != '\'') position++;
    *position = 0;
  } 
  else {
    // This is a normal token
    res.type = BASIC;
  }
  // Find the end of this token
  while (!isspace(*position) && *position != 0) position++;
  *position = 0;
  position++; // move it forward to be ready for the next call
  return res;
}

