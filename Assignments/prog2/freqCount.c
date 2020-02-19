#include <stdio.h> 
#include <string.h>
#include <ctype.h>

int countCharacters(char buffer[], char letter){
    int count = 0;
    for (int i = 0; i < strlen(buffer); i++)
    {
        if (tolower(buffer[i]) == letter)
        {
            count += 1;
        }
    }
    return count;
}

int main() 
{
    char buffer[1000];
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    fgets(buffer, 1000, stdin);
    for (int i = 0; i < strlen(letters); i++)
    {
        printf("%c: %d\n",  toupper(letters[i]), countCharacters(buffer, letters[i]));
    }
    return 0; 
}