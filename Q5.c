/* CS261- Assignment 1 - Q.5*/
/* Name:  Tim Thomas
 * Date:  4/7/2015
 * Solution description:  Working with character arrays to convert an input
 * string to sticky case.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>   // for toupper and tolower

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}


/******************************************************************************
 ** Function:         sticky 
 ** Description:      Converts a character array to sticky case (characters
 **                   alternate from upper/lower case, starting with uppercase.
 ** Parameters:       Pointer to char array. 
 ** Pre-Conditions:   legal string passed.
 ** Post-Conditions:  none.
 *****************************************************************************/
void sticky(char* word){
     /*Convert to sticky caps*/
    int i = 0;                     // loop control

    // loop until null terminator found
    while (word[i] != '\0') 
    {
        if (i % 2 == 0)   // even indices converted to upper case
        {
            word[i] = toupper(word[i]);
        }
        else              // odd indices converted to lower
        {
            word[i] = tolower(word[i]);
        }
        i++; 
    }
}


int main(){
    /*Read word from the keyboard using scanf*/
    char input[20];
    printf("\nInput a word less than 20 characters: ");
    scanf("%s", input);
    
    /*Call sticky*/
    sticky(input); 

    /*Print the new word*/
    printf("\nSticky case word is: %s\n", input);
    
    return 0;
}
