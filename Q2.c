/* CS261- Assignment 1 - Q.2*/
/* Name:  Tim Thomas
 * Date:  4/7/2015
 * Solution description:  Examining differences between passing pointers and
 * passing by value.
 */
 
#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
 ** Function:         foo 
 ** Description:      Performs operations and params passed as pointer and by
 **                   value. 
 ** Parameters:       Two pointers to int and one int 
 ** Pre-Conditions:   None. 
 ** Post-Conditions:  None. 
 *****************************************************************************/
int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a = 2 * (*a);
    
    /*Set b to half its original value*/
    *b = (*b) / 2;
    
    /*Assign a+b to c*/
    c = *a + *b;
    
    /*Return c*/
    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    int foo_val;   // holds value returned by foo()
    
    /*Print the values of x, y and z*/
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    foo_val = foo(&x, &y, z);
    
    /*Print the value returned by foo*/
    printf("value returned by foo = %d\n", foo_val);
    
    /*Print the values of x, y and z again*/
    printf("x = %d\n", x);
    printf("y = %d\n", y);
    printf("z = %d\n", z);
 
    /*Is the return value different than the value of z?  Why?*/
    /* yes, because only a local copy of z is modified in foo
     * not the original value.  This is because z is passed to foo by value, 
     * whereas, x and y are passed as pointers.  
     * Thus, the return value of foo is the modified copy of z and the original
     * value of z is unmodified. */
    return 0;
}
    
    
