#include "view.h"
#include "test_view.h"
#include <stdio.h>
#include <stdlib.h>

int test_view_lib(){
	
	char func[41];
	char error_msg[] = "test_error";
	int errcode2,print_error,graph;
	int error = 0;
	errcode2 = test_input(func);
	
	if (errcode2){
		printf("Error detected in input function. ");
		error = 1;
	}
	errcode2 = test_show_error(error_msg);
	if (errcode2){
		printf("Error detected in show_error function. ");
		error = 1;
	}
	errcode2 = test_graph();
	if (errcode2){
		printf("Error detected in graph function. ");
		error = 1;
	}
	if (error == 1){
		return 1;
	}
	return 0;
}

int test_input(char func[]){
	int errcode;
	char cor_func[41];
	
	freopen("input_test.txt", "r", stdin);
	errcode = input(func);
	freopen("CON", "r", stdin);
	
	FILE *input_test = fopen("input_test.txt", "r");
	fscanf(input_test, "%s", cor_func);
	
	for (int i=0; func[i] != '\0';i++){
		if (func[i] != cor_func[i]){
			return 1;
		}
	}

	return errcode;
}

int test_show_error(char error_msg[]){
	int print_error;
	char x[50];
	FILE *s1;
	freopen("s1.txt", "w", stdout);
	print_error = show_error(error_msg);
	freopen("CON", "w", stdout);
	s1 = fopen("s1.txt","r");
	fscanf(s1,"%s",x);
	fclose(s1);
	for (int i=0;x[i] != '\0';i++){
		if (x[i] != error_msg[i]){
			return 1;
		}
	}
	
	return print_error;
}

int test_graph(){
	int graph_error;
	float values_arr[] = { -10.0,-9.5,-9.0,-8.5,-8.0,-7.5,
	-7.0,-6.5,-6.0,-5.5,-5.0,-4.5,-4.0,-3.5,-3.0,-2.5,-2.0,-1.5,
	-1.0,-0.5,0,0.5,1.0,1.5,2.0,2.5,3.0,3.5,4.0,4.5,5.0,5.5,6.0,
	6.5,7.0,7.5,8.0,8.5,9.0,9.5,10.0,10.5};
	char y;
	char x[3500];
	FILE *s2, *s3;
	freopen("s2.txt", "w", stdout);
	graph_error = graph(values_arr);
	freopen("CON", "w", stdout);
	s2 = fopen("s2.txt","rb");
	s3 = fopen("s3.txt","rb");
	
	for (int i = 0; i < 3800; i++){
		fscanf(s2,"%c",x + i);
		if (x[i] == '\0'){
			
			break;	
		}
		
		
		//fscanf(s3,"%c",y);
	}
	fclose(s2);
	for (int i=0;x[i] != '\0';i++){
		fscanf(s3,"%c",&y);
		if (x[i] != y){
			printf("%d",i);
			return 1;
		}
		
	}
	fclose(s3);

	return graph_error;
}