//
//  cal_exercise.c
//  Excercise for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"

#define MAX_EXERCISES 100  			// Maximum number of exercises
#define MAX_EXERCISE_NAME_LEN 50	// Maximum length of the name of exercise


// To declare the structure of the exercises
static Exercise exercise_list[MAX_EXERCISES] = {0}; //added initializing process
int exercise_list_size = 0;


/*
    description : read the information in "excercises.txt"
*/

void loadExercises(const char* EXERCISEFILEPATH) {
    FILE *file = fopen(EXERCISEFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for exercises! \n");
        return;
    }

    // ToCode: to read a list of the exercises from the given file
    char c[MAX_EXERCISE_NAME_LEN]; //set string to receive data while reading file
    
    while ( fgets(c, MAX_EXERCISE_NAME_LEN, file) != NULL ) {
    	int i;
		int setter =1;
		
		for(i=0; i<MAX_EXERCISE_NAME_LEN; i++)
		{
			if( (c[i] >='0') && (c[i] <='9')) //if character is a number
			{
				if(setter) //end name of exercise with '\0' to prevent issues
				{
					exercise_list[exercise_list_size].exercise_name[i] = '\0';
					setter = 0;
				}
				
				if( exercise_list[exercise_list_size].calories_burned_per_minute == 0)
				exercise_list[exercise_list_size].calories_burned_per_minute = (c[i]-'0');
				else //if calories per minute is more than one digit long
				exercise_list[exercise_list_size].calories_burned_per_minute = exercise_list[exercise_list_size].calories_burned_per_minute*10 + (c[i]-'0');
			}
			else //if character is not a number
			exercise_list[exercise_list_size].exercise_name[i] = c[i];
		}
		    	
        if (exercise_list_size >= MAX_EXERCISES){
        	break;
		}
		
		exercise_list_size++; //increase exercise list size to save number of exercise read
    }

    fclose(file);
}


/*
    description : to enter the selected exercise and the total calories burned in the health data
    input parameters : health_data - data object to which the selected exercise and its calories are added 
    return value : No
    
    operation : 1. provide the options for the exercises to be selected
    			2. enter the duration of the exercise
    			3. enter the selected exercise and the total calories burned in the health data
*/

void inputExercise(HealthData* health_data) {
    int choice, duration, i;
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");


    // ToCode: to enter the exercise to be chosen with exit option

 
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    

}
