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
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    int id = 0; 
    int ids[10];

    int score = -1;  // initialize at -1 since 0 is valid score
    int scores[10];

    int unique_id = 1;  // flag to indicate unique id found (0 = false, 1 = true)

    int i, j;        // loop control variables

    /* Seed RNG */
    srand(time(NULL));

    /* initialize ids and scores */
    for (i = 0; i < 10; i++) 
    {
        ids[i] = id;
        scores[i] = score;
    }

    /* initialize ids[0] to a nonzero number */
    for (i = 0; i < 10; i++) 
    {
        id = 0;
        while (unique_id == 0 || id == 0) 
        {
            id = rand() % 10 + 1;

            for (j = 0; j < i; j++) 
            {
                if (id == ids[j]) 
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
        ids[i] = id;
        score = rand() % 100;
        students[i].id = id; 
        students[i].score = score;
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
