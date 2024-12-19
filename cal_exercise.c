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
static Exercise exercise_list[MAX_EXERCISES] = {0}; //adding initialization process
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
	while ( fscanf(file, "%s %d", &exercise_list[exercise_list_size].exercise_name, &exercise_list[exercise_list_size].calories_burned_per_minute) != EOF) {
		exercise_list_size++;
		
        if (exercise_list_size >= MAX_EXERCISES){
        	break;
		}
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

void inputExercise(HealthData* phealth_data) { //changing pointer name to strucutre data and pointer being under same name
    int choice, duration, i;
    
    // ToCode: to provide the options for the exercises to be selected
    printf("The list of exercises: \n");
    for(i=0;i<exercise_list_size;i++)
    printf("%i. %s (%i kcal burned per min.)\n", i+1, exercise_list[i].exercise_name, exercise_list[i].calories_burned_per_minute);
    
    
    // ToCode: to enter the exercise to be chosen with exit option
    printf("%i. Exit\n", exercise_list_size+1);
    scanf("%i", &choice);
    
    
    // To enter the duration of the exercise
    if(choice>0 && choice<=(exercise_list_size+1) )
    {
    	printf("Enter the duration of the exericse (in min.): ");
    	scanf("%d", &duration);
    	choice--; //adjusting number for easier calculation
	}
    
    // ToCode: to enter the selected exercise and total calcories burned in the health data
    if(duration>=0)
    {
    	strcpy(phealth_data->exercises[phealth_data->exercise_count].exercise_name, exercise_list[choice].exercise_name);
    	phealth_data->exercises[phealth_data->exercise_count].calories_burned_per_minute = exercise_list[choice].calories_burned_per_minute*duration;
    	phealth_data->total_calories_burned += phealth_data->exercises[phealth_data->exercise_count].calories_burned_per_minute;
		phealth_data->exercise_count++;
	}
	else
	printf("Returning to main screen");
	
}
