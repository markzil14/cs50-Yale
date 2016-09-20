#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
    
// create an array to store user input of a name
string s = get_string();

//create boolean values that reflect whether an iteration over 
//a name encountering a word (IN_WORD) or a space (OUT_OF_WORD)
#define IN_WORD 1
#define OUT_OF_WORD 0
int status = IN_WORD;

int print_this;

//in the case that there is no space before the beginning of the very first word inputted,
//print the very first character encountered
if (s[0] != ' ')
{
    print_this = s[0];
    print_this = toupper (print_this);
    printf("%c", print_this);
}

//interate over user input
for (int i = 0; i < strlen(s); i++)
    {
      
    //if the interation encounter a space, change the status to reflect that   
        if (s[i] == ' ')
        {
            status = OUT_OF_WORD;
        }
        
    //otherwise, if status = OUT_OF_WORD AND the iteration is encountering a 
    //character, that must mean this character is an initial! print it.  This ensures that
    //even if the user is sloppy and has multiple spaces before words, the program does not
    //mistakenly print the spaces
        else if (status == OUT_OF_WORD)
        {
            status = IN_WORD;
            print_this = s[i];
            print_this = toupper (print_this);
            printf("%c", print_this);
        }
        
    }

printf("\n");

}