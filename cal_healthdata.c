//
//  cal_healthdata.c
//  Diets for Calorie Diary
//
//  Created by Eunju Cha
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cal_exercise.h"
#include "cal_diets.h"
#include "cal_healthdata.h"


/*
    description : enter the exercise and diet history in "health_data.txt" 
    input parameters : health_data - data object in which the selected exercise and diet is stored
    return value : No
    
    operation : 1. save the chosen exercise and total calories burned 
    			2. save the chosen diet and total calories intake 
    			3. save the total remaining calrories
*/

void saveData(const char* HEALTHFILEPATH, const HealthData* phealth_data) {
	int i;
    FILE* file = fopen(HEALTHFILEPATH, "w");
    if (file == NULL) {
        printf("There is no file for health data.\n");
        return;
    }

    // ToCode: to save the chosen exercise and total calories burned 
    fprintf(file, "[Exercises] \n");
	for(i=0; i<phealth_data->exercise_count;i++)
    fprintf(file, "%s - %ikcal\n", phealth_data->exercises[i].exercise_name, phealth_data->exercises[i].calories_burned_per_minute);
	fprintf(file, "Total calories burned: %ikcal\n", phealth_data->total_calories_burned);
    
    
    // ToCode: to save the chosen diet and total calories intake 
    fprintf(file, "\n[Diets] \n");



    // ToCode: to save the total remaining calrories
    fprintf(file, "\n[Total] \n");
    
    
}

/*
    description : print the history of exercised and diets
    input parameters : health_data - data object in which the history of the exercise and diet is to be printed
    return value : No
    
    operation : 1. print out the saved history of exercises
    			2. print out the saved history of diets
    			3. print out the saved history of calories
*/

void printHealthData(const HealthData* phealth_data) {
	int i;
	
	// ToCode: to print out the saved history of exercises
	printf("=========================== History of Exercise =======================\n");
	for(i=0; i<phealth_data->exercise_count; i++)
	printf("Exercise: %s, calories burned: %i\n", phealth_data->exercises[i].exercise_name, phealth_data->exercises[i].calories_burned_per_minute);
    printf("=======================================================================\n");
    
    
    // ToCode: to print out the saved history of diets
    printf("============================= History of Diet =========================\n");
    for(i=0;i<phealth_data->diet_count;i++)
    printf("Food: %s, calories intake: %ikcal\n", phealth_data->diet[i].food_name, phealth_data->diet[i].calories_intake);
    printf("=======================================================================\n");
    
    
	// ToCode: to print out the saved history of calories including basal metabolic rate, 
	// total calories burned, total calories intake, and the remaining calories
	printf("============================== Total Calories =========================\n");
	printf("Basal Metabolic Rate: %i\n", BASAL_METABOLIC_RATE);
	printf("Total calories burned: %i\n", phealth_data->total_calories_burned);
	printf("Total calories intake: %i\n", phealth_data->total_calories_intake);
	printf("The remain calories: %i\n", phealth_data->total_calories_intake- BASAL_METABOLIC_RATE - phealth_data->total_calories_burned);
    printf("=======================================================================\n \n");
    
    
	// ToCode: to print out the recommendtaion depending on the current total calories burned and intake    
    
    
	 printf("=======================================================================\n");
}
