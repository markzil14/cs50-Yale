#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main( int argc, string argv[])
{
    //check that the user provides a command-line argument and turn it into an integer for enciphering purpose
    if (argc != 2)
    {
        printf ("missing command-line argument  \n");
        return 1;
    }
    int k = atoi(argv[1]);
    
    //as the user for a plain text
    printf("plaintext:");
    string p = get_string();

    // ci is the enciphered character; pi, the plain character
    printf("ciphertext:");
    int ci, pi;
   
    for (int i = 0; i < strlen(p); i++)
    {
      //Consider the cases of lower-case letters
      if (p[i] >= 'a' && p[i] <= 'z')
      {
        //convert the plain character to alphabetical index (0-25)
        pi = p[i] - 97;
        
        //find the alphabetical index for the enciphered character
        ci = (pi + k) % 26;
        
        //covert the ciphered character back to its ASCII code and print it
        ci = ci + 97;
        printf("%c", ci );
      }
      
      //Consider the cases of upper-case letters
      else if (p[i] >= 'A' && p[i] <= 'Z')
      {
        //convert the plain character to alphabetical index (0-25)
        pi = p[i] - 65;
        
        //find the alphabetical index for the enciphered character
        ci = (pi + k) % 26;
        
        //covert the ciphered character back to ASCII code and print it
        ci = ci + 65;
        printf("%c", ci );
      }
      
      else printf("%c", p[i]);
  }
    
    printf ("\n");
    
  
    
}
