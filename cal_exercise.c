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
static Exercise exercise_list[MAX_EXERCISES];
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
	char c[MAX_EXERCISE_NAME_LEN];
	
	while ( (fgets(c,MAX_EXERCISE_NAME_LEN,file)) != NULL ) {	//read line by line
			int i;
			int setter=1;
			for(i=0;i<30;i++)
			{				
				if(c[i] == '\0')
				continue;
				
				if( (c[i]>='0') && (c[i]<='9') )
				{
					if(setter) //placing NULL at the right place
					{
						exercise_list[exercise_list_size].exercise_name[i] = '\0';
						setter = 0;
					}
					
					if(exercise_list[exercise_list_size].calories_burned_per_minute == 0)
					exercise_list[exercise_list_size].calories_burned_per_minute = (c[i]-'0'); //saving character of number as integer
					else //if calories per min is a two digit number
					exercise_list[exercise_list_size].calories_burned_per_minute = exercise_list[exercise_list_size].calories_burned_per_minute*10 + (c[i]-'0');
				}
				else //if not number, save as character in the name
				exercise_list[exercise_list_size].exercise_name[i] = c[i]; //using i since the text file starts with the exercise name
			}
    	
        if (exercise_list_size >= MAX_EXERCISES){
        	break;
		}
		exercise_list_size++;
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
    for(i=0; i<exercise_list_size;i++)
    printf("%i. %s (%i kcal burned per min.)\n", i+1, exercise_list[i].exercise_name, exercise_list[i].calories_burned_per_minute);

    // ToCode: to enter the exercise to be chosen with exit option
    printf("%i. Exit\n", exercise_list_size+1);
	printf("Choose (1-7) : ");
	scanf("%d", choice);
    
    // To enter the duration of the exercise
    printf("Enter the duration of the exercise (in min.): ");
    scanf("%d", &duration);
    

    // ToCode: to enter the selected exercise and total calcories burned in the health data
    

}
