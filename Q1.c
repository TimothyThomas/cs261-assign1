/* CS261- Assignment 1 - Q.1*/
/* Name: Tim Thomas
 * Date: 4/4/2015
 * Solution description:  Allocating memory for a struct.  Using rand() to
 * generate random values within specified limits.  Accessing and printing
 * values within a struct.  Freeing memory.
 */
 
#include <stdio.h>
#include <stdlib.h>   
#include <math.h>
#include <time.h>    

struct student{
	int id;
	int score;
};

/******************************************************************************
 ** Function:         allocate() 
 ** Description:      Allocates memory for an array of struct student 
 ** Parameters:       None. 
 ** Pre-Conditions:   None.
 ** Post-Conditions:  Returns pointer to array. 
 *****************************************************************************/
struct student* allocate(){
     /*Allocate memory for ten students*/
    int num = 10;
    struct student *ptr = malloc(num * sizeof(struct student));
     
     /*return the pointer*/
    return ptr;
}


/******************************************************************************
 ** Function:         generate() 
 ** Description:      Generates scores and IDs for studnets. 
 ** Parameters:       Pointer to students. 
 ** Pre-Conditions:   students must be initialized. 
 ** Post-Conditions:  students is populated with IDs and values for each student 
 *****************************************************************************/
void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and
      * 10, scores between 0 and 100*/

    int i, j;           // loop control variables
    int unique_id = 0;  // flag to indicate unique id found (0 = false, 1 = true)

    /* Seed RNG */
    srand(time(NULL));

    /* Set ID/score of 1st student (since 1st ID guaranteed to be unique) */
    students[0].id = rand() % 10 + 1;
    students[0].score = rand() % 100 + 1;
    
    /* Loop through rest of students and generate a score and id for each */
    for (i = 1; i < 10; i++) 
    {
        /* continue generating IDs until a unique one is found */
        while (unique_id == 0) 
        {
            students[i].id = rand() % 10 + 1;

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
}


/******************************************************************************
 ** Function:         output 
 ** Description:      Prints unsorted IDs and scores for all students. 
 ** Parameters:       Pointer to students. 
 ** Pre-Conditions:   generate function should have been called 
 ** Post-Conditions:  prints output to screen 
 *****************************************************************************/
void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

    int i;   // loop control

    // Loop through each student and output ID and Score (unsorted)
    for (i = 0; i < 10; i++)
    {
        printf("%d %d\n", students[i].id, students[i].score);
    }
}


/******************************************************************************
 ** Function:         summary() 
 ** Description:      Prints min, max and average score of ten students 
 ** Parameters:       Pointer to student 
 ** Pre-Conditions:   generate function should be run. 
 ** Post-Conditions:  none. 
 *****************************************************************************/
void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i;                 // loop control
    int min, max, sum;     
    double avg;

    min = 100;
    max = 0;
    sum = 0;

    // Loop through all values finding min, max and calculating sum
    for (i = 0; i < 10; i++) 
    {
        if (students[i].score > max)  
        {
            max = students[i].score;
        }

        if (students[i].score < min)  
        {
            min = students[i].score;
        }

        sum += students[i].score;
    }

    // computer average
    avg = sum / 10.0; 
    
    printf("Minimum score is: %d\n", min);
    printf("Maximum score is: %d\n", max);
    printf("Average score is: %.2f\n", avg);
}


/******************************************************************************
 ** Function:         deallocate() 
 ** Description:      De-Allocates memory. 
 ** Parameters:       Pointer to students. 
 ** Pre-Conditions:   students must != NULL 
 ** Post-Conditions:  memory freed. 
 *****************************************************************************/
void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    if (stud != 0) 
    {
        free(stud); 
    }
    return;
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    
    /*call generate*/
    generate(stud);
    
    /*call output*/
    output(stud);
    
    /*call summary*/
    summary(stud);
    
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
