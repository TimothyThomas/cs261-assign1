/* CS261- Assignment 1 - Q.1*/
/* Name: Tim Thomas
 * Date: 4/4/2015
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>   
#include <math.h>
#include <time.h>    

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    int num = 10;
    struct student *ptr = malloc(num * sizeof(struct student));
     
     /*return the pointer*/
    return ptr;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and
      * 10, scores between 0 and 100*/

    int i, j;           // loop control variables
    int unique_id = 0;  // flag to indicate unique id found (0 = false, 1 = true)

    /* Seed RNG */
    srand(time(NULL));

    /* Initialize ID/score of first student (since ID guaranteed to be unique) */
    students[0].id = rand() % 10 + 1;
    students[0].score = rand() % 100 + 1;
    
    /* Loop through each student and generate a score and id for each */
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

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

    int i;   // loop control

    for (i = 0; i < 10; i++)
    {
        printf("%d %d\n", students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i, min, max, sum;
    double avg;
    min = 100;
    max = 0;
    sum = 0;

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
    avg = sum / 10.0; 
    
    printf("Minimum score is: %d\n", min);
    printf("Maximum score is: %d\n", max);
    printf("Average score is: %.2f\n", avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
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

    return 0;
}
