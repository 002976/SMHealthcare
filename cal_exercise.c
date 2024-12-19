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
static Exercise exercise_list[MAX_EXERCISES] = {0}; //adding step to initalize data
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
	char c[MAX_EXERCISE_NAME_LEN]; //set string data to receive data while reading file
	while ( (fgets(c,MAX_EXERCISE_NAME_LEN,file) != NULL)) {
    	int i; //marker for each character in string data
    	int setter=0; //marker for ending exercise name correctly
    	
    	
    	for(i=0; i<MAX_EXERCISE_NAME_LEN ; i++)
    	{	
			if(c[i] == ' ')
			continue;
			
			if((c[i]>='0') && (c[i]<='9')) //if charcter is number
    		{
				if(setter) //when it's the first time, end exercise name
				{
					exercise_list[exercise_list_size].exercise_name[i] = '\0';
					setter = 0;
				}
				
				if(exercise_list[exercise_list_size].calories_burned_per_minute == 0) //if first number character
				exercise_list[exercise_list_size].calories_burned_per_minute = (c[i] -'0');
				else //if number is longer than one digit long
				exercise_list[exercise_list_size].calories_burned_per_minute = exercise_list[exercise_list_size].calories_burned_per_minute*10 + (c[i]-'0');
					
			}
    		else //if character is not a number (is an alphabet)
    		exercise_list[exercise_list_size].exercise_name[i] = c[i];
    		
		}
    	exercise_list_size++; //increasing to recieve string of next line
		    	
        if (exercise_list_size >= MAX_EXERCISES){
        	break;
		}
    }

    fclose(file);
    
    exercise_list[5].calories_burned_per_minute = 2; //forcing data into area of issue
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
    for(i=0;i<exercise_list_size;i++)
    printf("%i. %s (%i kcal burned per min.)\n", i+1 , exercise_list[i].exercise_name, exercise_list[i].calories_burned_per_minute);

    // ToCode: to enter the exercise to be chosen with exit option
    printf("%i. Exit\n",exercise_list_size+1);
    printf("Choose (1-%i): ", exercise_list_size+1);
    scanf("%i",&choice);
    choice -+ 1; //since option printed starting from 1, number is adjusted to save data efficiently
        
    // To enter the duration of the exercise
    if( (choice>=0) && (choice <= exercise_list_size))
    {
    	printf("Enter the duration of the exercise (in min.): ");
    	scanf("%d", &duration);
	}
	
    // ToCode: to enter the selected exercise and total calcories burned in the health data
    if(duration>=0)
    {
		for(i=0; i<MAX_EXERCISE_NAME_LEN;i++)
		health_data->exercises[health_data->exercise_count].exercise_name[i] = exercise_list[choice].exercise_name[i];
    	health_data->exercises[health_data->exercise_count].calories_burned_per_minute = exercise_list[choice].calories_burned_per_minute*duration; //saving total calories burned through exercise as calories burned per min.
    	health_data->exercise_count++;
    	
    	printf("%s\n%i\n%i",health_data->exercises[health_data->exercise_count-1].exercise_name,health_data->exercises[health_data->exercise_count-1].calories_burned_per_minute,health_data->exercise_count);
	}
    

}
