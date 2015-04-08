/* CS261- Assignment 1 - Q.3*/
/* Name:  Tim Thomas
 * Date:  4/7/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>   
#include <time.h>    

void sort(int* numbers, int n){
    /*Sort the given array number , of length n*/     
    int i, j;
    int temp;

    for (i = n - 1; i > 0; i--) 
    {
        for (j = 0; j < i; j++)
        {
            if (numbers[j] > numbers[j + 1]) 
            {
                temp = numbers[j];    
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *nums = malloc(n * sizeof(int));
    
    /*Fill this array with random numbers, using rand().*/
    srand(time(NULL));   /* Seed RNG */
    int i;
    for (i = 0; i < n; i++)
    {
        nums[i] = rand() % 100;
    }
    
    /*Print the contents of the array.*/
    printf("\nUnsorted numbers; \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }
    

    /*Pass this array along with n to the sort() function of part a.*/
    sort(nums, n);
    
    /*Print the contents of the array.*/    
    printf("\nSorted numbers; \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", nums[i]);
    }

    
    return 0;
}
