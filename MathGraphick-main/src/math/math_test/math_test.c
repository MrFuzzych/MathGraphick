#include "math.h"
#include <stdio.h>
#include <stdlib.h>
#include "math_test.h"

int test_math_lib(){
	int ecode;
	int error = 0;
	ecode = test_create_values_arr();
	if (ecode){
		printf("Error detected in create_values_arr function. ");
		error = 1;
	}
	ecode = test_parse();
	if (ecode){
		printf("Error detected in parse function. ");
		error = 1;
	}
	ecode = test_priority();
	if (ecode){
		printf("Error detected in priority function. ");
		error = 1;
	}
	if (error == 1){
		return 1;
	}
	
	return 0;
}

int test_create_values_arr(){
	float values_arr[41];
	float correct_values[] = {-9.000, -8.500, -8.000, -7.500, -7.000, -6.500,
	-6.000, -5.500, -5.000, -4.500, -4.000, -3.500, -3.000, -2.500, -2.000, -1.500,
	-1.000, -0.500, 0.000, 0.500, 1.000, 1.500, 2.000, 2.500, 3.000, 3.500, 4.000, 
	4.500, 5.000, 5.500, 6.000, 6.500, 7.000, 7.500, 8.000, 8.500, 9.000, 9.500, 
	10.000, 10.500, 11.000};
	int ecode = create_values_arr("x+1", values_arr);
	if (!ecode){
		for (int i = 0; i <= 40; i++){
			if (values_arr[i] != correct_values[i]){
				return 1;
			}
		}
	}
	return ecode;
}

int test_parse(){
	float x = 2.;
	float correct_res = 3.;
	float res;
	int ecode = parse("x+1", &res, x);
	if (!ecode){
		if (res != correct_res){
			return 1;
		}
	}
	
	return ecode;
}

int test_priority(){
	char operators[] = {'+', '-', '*', '/', 's', 'c', 't', 'o', 'l', '^'};
	int priorities[] = {1, 1, 2, 2, 3, 3, 3, 3, 3, 4};
	int res;
	for (int i = 0; i < 10; i++){
		res = priority(operators[i]);
		if (res != priorities[i]){
			return 1;
		}
		else{
			return 0;
		}
	}
	
	
}

