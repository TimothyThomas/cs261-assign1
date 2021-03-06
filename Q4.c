/* CS261- Assignment 1 - Q.4*/
/* Name:  Tim Thomas
 * Date:  4/11/2015
 * Solution description:  Sorting a struct by accessing its data.
 */
 
#include <stdio.h>
#include <stdlib.h>

struct student{
	int id;
	int score;
};


/******************************************************************************
 ** Function:         sort 
 ** Description:      Sorts an array of student structs based on scores 
 **                   Uses bubble sort.
 ** Parameters:       Pointer to array and size of array. 
 ** Pre-Conditions:   none. 
 ** Post-Conditions:  none. 
 *****************************************************************************/
void sort(struct student* students, int n){
    /*Sort the n students based on their score*/     
    int i, j;              // loop control
    struct student temp;   // temp struct for swapping

    /* bubble sort */
    for (i = n - 1; i > 0; i--) 
    {
        for (j = 0; j < i; j++)
        {
            if (students[j].score > students[j + 1].score) 
            {
                temp = students[j];    
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}


/* Much of the code in main is from functions implemented in Q1.c */
int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 10;
    
    /*Allocate memory for n students using malloc.*/
    struct student *students = malloc(n * sizeof(struct student));
    
    /*Generate random IDs and scores for the n students, using rand().*/
    int i, j;           // loop control variables
    int unique_id = 0;  // flag to indicate unique id found (0 = false, 1 = true)

    /* Seed RNG */
    srand(time(NULL));

    /* Initialize ID/score of first student (since ID guaranteed to be unique) */
    students[0].id = rand() % n + 1;
    students[0].score = rand() % 100 + 1;
    
    /* Loop through each student and generate a score and id for each */
    for (i = 1; i < n; i++) 
    {
        /* continue generating IDs until a unique one is found */
        while (unique_id == 0) 
        {
            students[i].id = rand() % n + 1;

            /* check that ID does not equal previously generated IDs */
            for (j = 0; j < i; j++) 
            {
                if (students[i].id == students[j].id) 
                {
                    unique_id = 0;
                    break;
                }
                else
                {
                    unique_id = 1;
                }
            }
        }

        unique_id = 0;
        students[i].score = rand() % 100 + 1;
    }

    /*Print the contents of the array of n students.*/
    printf("\nUnsorted IDs and Scores: \n");
    for (i = 0; i < 10; i++)
    {
        printf("%d %d\n", students[i].id, students[i].score);
    }

    /*Pass this array along with n to the sort() function*/
    sort(students, n);
    
    /*Print the contents of the array of n students.*/
    printf("\nSorted by student score: \n");
    for (i = 0; i < 10; i++)
    {
        printf("%d %d\n", students[i].id, students[i].score);
    }
    
    return 0;
}
