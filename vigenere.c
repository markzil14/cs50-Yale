#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main( int argc, string argv[])
{
    //check that the user provides a command-line argument 
    //that can be used as k for ciphering purpose
    if (argc != 2)
    {
        printf ("missing command-line argument  \n");
        return 1;
    }
    
    //check that the command line argument is exclusively alphabetic
    for (int j = 0; j < strlen(argv[1]); j++)
    {
        if (isalpha(argv[1][j]) == false)
        {
            printf ("opps! this is awkward, but it looks like we only accept alphabetic characters  \n");
            return 1;
        }
    }
    
    //since there is no distinction between 'A' and 'a' for keywords,
    //we will capitalize the keyword in order to more conveniently convert it to numeric key later
    for (int k = 0; k < strlen(argv[1]); k++)
    {
        argv[1][k] = toupper(argv[1][k]);
    }
    
    //store the keyword and plain text
    string keyword = argv[1];
    printf("plaintext:");
    string p = get_string();
    
    
    printf("ciphertext:");
   
    //pi is the plain text character currently iterated over; 
    //ki, corresponding key for enciphering;
    //ci, enciphered text charactered.
    int pi, ki, ci;
    
    //adjustment helps keeps track of the non-alphabetic characters we encounter
    int adjustment = 0;
    int k = strlen(keyword);
  
   
  for (int i = 0; i< strlen(p);  i++)
  {
      //dealing with lower cases:
      if (p[i] >= 'a' && p[i] <= 'z')
      {
        //convert the plain text character to its alphabetical index
        pi = p[i] - 97;
        
        //get the key for the plain text character
        ki = keyword[(i - adjustment) % k] ;
        
        //convert this key to its alphabetic index
        ki = ki - 65;
        
        //determine the enciphered character and convert it back to ASCII code and print it
        ci = (pi + ki) % 26;
        ci = ci+ 97;
        printf ("%c", ci);
      }
      
      //dealing with upper cases:
      else if (p[i] >= 'A' && p[i] <= 'Z')
      {
        //convert the plain text character to its alphabetical index
        pi = p[i] - 65;
        
        //get the key for the plain text character
        ki = keyword[(i - adjustment) % k ] ;
        
        //convert this key to its alphabetic index
        ki = ki - 65;
        
        //determine the enciphered character and convert it back to ASCII code and print it
        ci = (pi + ki) % 26;
        ci = ci+ 65;
        printf ("%c", ci);
      }
      
      //print out non-alphabetic characters and increment the adjusment variable,
      //which is used to determine the correct ki (key) fo the next alphabetic character
      else 
      { 
          printf("%c", p[i]);
          ++adjustment;
      }
  }
    
    printf ("\n");
    
  
    
}
