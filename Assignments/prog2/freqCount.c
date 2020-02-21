#include <stdio.h> 
#include <string.h>
#include <ctype.h>

int frequency[26];

void countCharacters(char letter){
    char upperCaseLetter = toupper(letter);
    if (upperCaseLetter >= 'A' && upperCaseLetter <= 'Z')
    {
        int order = upperCaseLetter - 'A';
        frequency[order]++;
    }
}

int main() 
{
    int c = fgetc(stdin);
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    while (c != EOF)
    {
        countCharacters(c);
        c = fgetc(stdin);
    }
    for (int i = 0; i < strlen(letters); i++)
    {
        printf("%c: %d\n",  toupper(letters[i]), frequency[i]);
    }
    return 0; 
}