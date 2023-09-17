#include "math.h"
#include "error_proc.h"
#include "save.h"
#include "view.h"
#include <stdio.h>
#include <string.h>

int main(){
	char func[40];
	float values_arr[41];
	int ecode = 0;
	int func_found = 0;
	int n = 0;

	while (1){
		ecode = input(func);
		if (ecode){
				//printf("1");
			error_value(ecode);
			continue;
		}
		if (func[0] == 'e' && func[1] == 'x' && func[2] == 'i' && func[3] == 't' && func[4] == '\0'){
			printf("goodbye");
			break;
		}
	/*
		ecode = get_function(func, values_arr, &func_found);
		if (ecode){
				//printf("2");
			error_value(ecode);
			return 1;
		}

		if (func_found){
			ecode = graph(values_arr);
			if (ecode){
						//printf("3");
			error_value(ecode);
			return 1;
				}
		}

		else{

			ecode = create_values_arr(func, values_arr);
			if (ecode){
				error_value(ecode);
				return 1;
			}
			ecode = graph(values_arr);
			if (ecode){
					//printf("5");
				error_value(ecode);
				return 1;
			}
			ecode = save_function(func, values_arr);
			if (ecode){
					//printf("6");
				error_value(ecode);
				return 1;
			}
		}
		*/

		ecode = create_values_arr(func, values_arr);
		if (ecode){
			error_value(ecode);
			continue;
		}
		ecode = graph(values_arr);
		if (ecode){
				//printf("5");
			error_value(ecode);
			continue;
		}

		//memset(func, '\0', 40);
		//printf("%s\n", func);
		//memset(values_arr, '\0', 41);
		ecode = 0;
		func_found = 0;
	}

	return  0;

}
