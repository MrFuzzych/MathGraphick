#include "Save.h"
#include <stdio.h>
#include <stdlib.h>
#include "save_test.h"


int test_save_lib(){
	int ecode;
	int error = 0;
	ecode = test_get_function();
	if (ecode){
		printf("Error in get_function ");
		error = 1;
	}
	ecode = test_save_function();
	if (ecode){
		printf("Error in save_function ");
		error = 1;
	}
	if (error == 1){
		return 1;
	}
	return 0;
}


int test_get_function(){
	int func_found = 0;
	char function[] = "x^2+x+5";
	float values_arr[41];
	float correct_values[] = {1.000, 2.000, 3.000, 4.000, 5.000, 6.000,
	 7.000, 8.000, 9.000, 10.000, 11.000, 12.000, 13.000,
	 14.000, 15.000, 16.000, 17.000, 18.000, 19.000, 20.000, 21.000, 22.000,
	  23.000, 24.000, 25.000, 26.000, 27.000, 28.000,
	 29.000, 30.000, 31.000, 32.000, 33.000, 34.000, 35.000, 36.000,
	  37.000, 38.000, 39.000, 4003828.000, 41.000};
	int ecode = get_function("x^2+x+5", values_arr, &func_found);
	if (!ecode){
		for (int i = 0; i < 41; i++){
			if (values_arr[i] != correct_values[i]){
				return 1;
			}
		}
	}
	return ecode;
}


int test_save_function(){
	int func_found = 0;
	char function[] = "x+2*x-5";
	float values_arr[41];
	float correct_values[] = {-9.000, -8.500, -8.000, -7.500, -7.000, -6.500,
	-6.000, -5.500, -5.000, -4.500, -4.000, -3.500, -3.000, -2.500, -2.000, -1.500,
	-1.000, -0.500, 0.000, 0.500, 1.000, 1.500, 2.000, 2.500, 3.000, 3.500, 4.000,
	4.500, 5.000, 5.500, 6.000, 6.500, 7.000, 7.500, 8.000, 8.500, 9.000, 9.500,
	10.000, 10.500, 11.000};
	int ecode = save_function("x+2*x-5", correct_values);

	get_function("x+2*x-5", values_arr, &func_found);
	if (!ecode){
		for (int i = 0; i < 41; i++){
			if (values_arr[i] != correct_values[i]){
			    printf ("%.3f %.3f", values_arr[i], correct_values[i]);
				return 1;
			}
		}
	}
	printf(ecode);
	return ecode;
}
