/* CS261- Assignment 1 - Q.5*/
/* Name:  Tim Thomas
 * Date:  4/7/2015
 * Solution description:
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

void sticky(char* word){
     /*Convert to sticky caps*/
    int i = 0;
    while (word[i] != '\0') 
    {
        if (i % 2 == 0)
        {
            word[i] = toupper(word[i]);
        }
        else
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
    scanf("%s", &input);
    
    /*Call sticky*/
    sticky(input); 

    /*Print the new word*/
    printf("\nSticky case word is: %s\n", input);
    
    return 0;
}
