/* CS261- Assignment 1 - Q. 0*/
/* Name: Tim Thomas
 * Date: 4/4/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
     printf("The value of the integer (x) pointed to by iptr = %i\n", *iptr);
     
     /*Print the address pointed to by iptr*/
     printf("The address pointed to by iptr = %p\n", iptr);     
     
     /*Print the address of iptr itself*/
     printf("The address of iptr itself = %p\n", &iptr);     
}

int main(){
    
    /*declare an integer x*/
    int x;
    
    /*print the address of x*/
    printf("The address of x = %p\n", &x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*print the value of x*/
    printf("The value of x = %i\n", x);
    
    return 0;
}
