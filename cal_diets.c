//
//  cal_diets.c
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

#define MAX_DIETS 100      			// Maximum number of diets
#define MAX_FOOD_NAME_LEN 50		// Maximum length of the name of food


// list of diets 
static Diet diet_list[MAX_DIETS];
static int diet_list_size = 0;


/*
    description : read the information in "diets.txt"
*/

void loadDiets(const char* DIETFILEPATH) {
    FILE *file = fopen(DIETFILEPATH, "r");
    if (file == NULL) {
        printf("There is no file for diets! \n");
        return;
    }

     // ToCode: to read a list of the diets from the given file
    while ( fscanf(file, "%s %i", &diet_list[diet_list_size].food_name, &diet_list[diet_list_size].calories_intake) != EOF ) {
    	diet_list_size++;
    	
        if (diet_list_size >= MAX_DIETS){
        	break;
		}
    }
    fclose(file);
}

/*
    description : to enter the selected diet and the total calories intake in the health data
    input parameters : health_data - data object to which the selected diet and its calories are added 
    return value : No
    
    operation : 1. provide the options for the diets to be selected
    			2. enter the selected diet and the total calories intake in the health data
*/

void inputDiet(HealthData* phealth_data) { //changing pointer name
    int choice, i;
    
    // ToCode: to provide the options for the diets to be selected
    printf("The list of diets:\n");
    for(i=0;i<diet_list_size;i++)
    printf("%i. %s (%i kcal)\n",i+1,diet_list[i].food_name,diet_list[i].calories_intake);
	    
    
	// ToCode: to enter the diet to be chosen with exit option
    printf("%i. Exit\n", diet_list_size+1);
    printf("Choose (1-%i): \n", diet_list_size+1);
    scanf("%i", &choice);
    choice--;

    // ToCode: to enter the selected diet in the health data
    // ToCode: to enter the total calories intake in the health data
    if(choice>=0 && choice<=diet_list_size)
    {
    	strcpy(phealth_data->diet[phealth_data->diet_count].food_name, diet_list[choice].food_name);
    	phealth_data->diet[phealth_data->diet_count].calories_intake = diet_list[choice].calories_intake;
    	phealth_data->total_calories_intake += diet_list[choice].calories_intake;
    	phealth_data->diet_count++;
	}
	else
	printf("Exiting. Returning to main screen.\n");
	
}

