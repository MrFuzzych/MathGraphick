#include "save_test.h"
#include "math_test.h"
#include "test_view.h"
#include <stdio.h>

void main(){
	int error = 0;

	int ecode = test_save_lib();
	if (ecode){
		printf("Error detected in save lib. ");
		error = 1;
	}

    	ecode = test_math_lib();
	if (ecode){
		printf("Error detected in math lib. ");
		error = 1;
	}

	ecode = test_view_lib();
	if (ecode){
		printf("Error detected in view lib. ");
		error = 1;
	}

	if (error){
		printf("No errors found.");
	}
}