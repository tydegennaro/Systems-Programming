//   CSC 399: Systems Programming

// Program Name: 
//   freqCount.c

// Program Purpose:
//   This program reads in a file from stdin
//   and counts the frequency of each character in 
//   the file, and prints the results to screen. 

// Author(s):
//   Kyle DeGennaro
//   Tyler DeGennaro
//   Joey Germain

#include <stdio.h> 
#include <string.h>
#include <ctype.h>

int frequency[26];

// Function: countCharacters(char letter)
// Takes a character as an argument
// And increases the count everytime based
// on its frequency in the file.
void countCharacters(char letter){
    char upperCaseLetter = toupper(letter);
    // If the letter is greater than `A` and less than `Z`
    if (upperCaseLetter >= 'A' && upperCaseLetter <= 'Z')
    {
    	// Subtract `A` from the letter to get its position in the 
	// frequency array
        int order = upperCaseLetter - 'A';
	// Increment the index for the letter by 1. 
        frequency[order]++;
    }
}

int main() 
{
    // Read one character from stdin
    int c = fgetc(stdin);
    // Array of letters
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    // While the character (A letter from the file from stdin) is not end of file
    while (c != EOF)
    {
        countCharacters(c);
     	// Get the next character (letter) from the line in the file
        c = fgetc(stdin);
    }
    // Print out the frequency of each letter
    for (int i = 0; i < strlen(letters); i++)
    {
        printf("%c: %d\n",  toupper(letters[i]), frequency[i]);
    }
    return 0; 
}
