#include "error_proc.h"
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


int priority(char opr);

int parse(char func[], float* res, float x);


int create_values_arr(char func[], float values_arr[]){
	float res;
	int ecode;
	int n = 0;
	for (float x = -10; x <= 10;  x += 0.5){
		ecode = parse(func, &res, x);
		if (ecode){
			return ecode;
		}
		values_arr[n++] = res;
	}
	return 0;
}

int parse(char func[], float* res, float x){
	char num[10]; // Строка для записи числа
	int n = 0; // Индекс для строки числа
	float number;
	char symb;

	float numbers_stack[30]; // Стек для чисел
	int ns_index = -1; // Индекс текущего числа в стеке
	char operators_stack[30]; // Стек для операторов
	int os_index = -1; // Индекс текущего оператора в стеке

	char operator1;
	char operator2;

	int end_flag = 0;
	int par_end_flag = 0;
	int symb_is_opr = 0;
	int operator_is_unaric = 0;
	int next_is_neg = 0;
	int ns_index_bef_bracket = -1;

	int dots;
	int minuses;

	for(int i = 0; !end_flag; i++){
		symb = func[i];
		if ((48 <= symb) && (symb <= 57)/* || (symb == '-' && (ns_index == -1 || operators_stack[os_index] == '(')*/){			// Если попалась цифра
			dots = 0;
			minuses = 0;
			for (int j = i; 48 <= func[j] && func[j] <= 57 || func[j] == '.' /*|| (func[j] == '-' && n == 0)*/; j++){ // Запись числа в строку
				if (func[j] == '.'){
					dots++;
					if (dots == 2){
						return INPUT_ERR;
					}
				}
				//printf("%c", func[j]);
				if (func[j] == '-'){
					minuses++;
					if (minuses == 2){
						return INPUT_ERR;
					}
				}

				num[n] = func[j];
				//printf("%c", num[n]);
				n++;
				if (j > i){
					i++;
				}
			}
			number = atof(num); // Запись числа как float
			if (next_is_neg){
			    number *= -1;
			    next_is_neg = 0;
			}
			memset(num, '\0', 10);

			n = 0;
			ns_index++;
			numbers_stack[ns_index] = number; // Добавление числа в стек
			//printf("!%.1f!", numbers_stack[ns_index]);
			//printf(" %.3f ", numbers_stack[ns_index]);

		}
		else{ // Если попалась не цифра
			symb_is_opr = 0;

			switch(symb){
				case '+':
					symb_is_opr = 1;
					//printf("yy");
					if (os_index == -1){ // Если это первый оператор
						operators_stack[++os_index] = symb;
						continue; // Пропускаем ход, так как не с чем сравнивать.
					}
					break;
				case '-':
					if (ns_index == -1 || (operators_stack[os_index] == '(' && ns_index_bef_bracket == ns_index)){
					    next_is_neg = 1;
					    //printf("*");
					}
					else{
					    symb_is_opr = 1;
					    //printf("#");
					    if (os_index == -1){

						    operators_stack[++os_index] = symb;
						    continue;
					    }
					}

					break;
				case '/':
					symb_is_opr = 1;

					if (os_index == -1){
						operators_stack[++os_index] = symb;
						continue;
					}
					break;
				case '*':
					symb_is_opr = 1;
					if (os_index == -1){
						operators_stack[++os_index] = symb;
						continue;
					}
					break;
				case '^':
					symb_is_opr = 1;
					if (os_index == -1){
						operators_stack[++os_index] = symb;
						continue;
					}
					break;
				case 's':
					if (func[i+1] == 'i' && func[i+2] == 'n'){
						symb_is_opr = 1;
						operators_stack[++os_index] = symb;
						i+=2;
						continue;
					}
					else{
						return INPUT_ERR;
					}
					break;
				case 'c':
					if (func[i+1] == 'o' && func[i+2] == 's'){
						symb_is_opr = 1;
						operators_stack[++os_index] = symb;
						i+=2;
						continue;
					}
					else{
						if (func[i+1] == 'o' && func[i+2] == 't'){
							symb_is_opr = 1;
							operators_stack[++os_index] = 'o';
							i+=2;
							continue;
						}
						else{
							return INPUT_ERR;
						}

					}
					break;
				case 't':
					if (func[i+1] == 'a' && func[i+2] == 'n'){
						symb_is_opr = 1;
						operators_stack[++os_index] = symb;
						i+=2;
						continue;
					}
					else{
						return INPUT_ERR;
					}
					break;
				case 'l':
					if (func[i+1] == 'o' && func[i+2] == 'g'){
						symb_is_opr = 1;
						operators_stack[++os_index] = symb;
						i+=2;
						continue;
					}
					else{
						return INPUT_ERR;
					}
					break;
				case 'p':
					if (func[i+1] == 'i'){
						numbers_stack[++ns_index] = M_PI;
						i++;
						continue;
					}
					else{
						return INPUT_ERR;
					}
				case '(':
					operators_stack[++os_index] = symb;
					ns_index_bef_bracket = ns_index;
					//printf("**");
					continue;
				case ')':
					par_end_flag = 1;
					break;
				case 'x':
					numbers_stack[++ns_index] = x;
					if (next_is_neg){
					 numbers_stack[ns_index] *= -1;
					 next_is_neg = 0;
					}
					//printf("%.2f*", numbers_stack[ns_index]);
					break;
				case '\0': // Если дошли до конца строки.
					end_flag = 1;
					break;
				case ' ':
					continue;
				default:
					return INPUT_ERR;
					break;
			}

			if(symb_is_opr && os_index >= 0 || end_flag || par_end_flag){
				operator1 = operators_stack[os_index];
				//if (end_flag) printf(" %c ", operator1);
				operator2 = symb;
				//printf("%c", operator1);
				while ((priority(operator2) <= priority(operator1)) && operator1 != '(' || end_flag || par_end_flag){ // Если приоритет текущего оператора меньше приоритета предыдущего
					switch(operator1){
						case '+':
						    //printf("%.3f+%.3f = ", numbers_stack[ns_index - 1], numbers_stack[ns_index]);
							numbers_stack[ns_index - 1] = numbers_stack[ns_index - 1] + numbers_stack[ns_index];
							//printf("%.2f | ", numbers_stack[ns_index - 1]);

							//printf("@");
							break;
						case '-':
						    //printf("%.3f-%.3f | ", numbers_stack[ns_index - 1], numbers_stack[ns_index]);
							//printf("!");
							//printf("%.3f %.3f | ", numbers_stack[ns_index - 1], numbers_stack[ns_index]);
							//printf("(%.2f - %.2f) ", numbers_stack[ns_index - 1], numbers_stack[ns_index]);
							numbers_stack[ns_index - 1] = numbers_stack[ns_index - 1] - numbers_stack[ns_index];

							//printf("%.2f ", numbers_stack[ns_index-1]);
							break;
						case '*':
							numbers_stack[ns_index - 1] = numbers_stack[ns_index - 1] * numbers_stack[ns_index];
							//printf("$");
							break;
						case '/':
							if (numbers_stack[ns_index] == 0.){
								*res = 11;
								return 0;
							}
							numbers_stack[ns_index - 1] = numbers_stack[ns_index - 1] / numbers_stack[ns_index];

							break;
						case 's':
							numbers_stack[ns_index] = sin(numbers_stack[ns_index]);
							operator_is_unaric = 1;
							break;
						case 'c':
							numbers_stack[ns_index] = cos(numbers_stack[ns_index]);
							operator_is_unaric = 1;
							break;
						case 't':
							if (numbers_stack[ns_index] / M_PI / 2 == (int)(numbers_stack[ns_index] / M_PI / 2)){
								*res = 11;
								return 0;
							}
							numbers_stack[ns_index] = tan(numbers_stack[ns_index]);
							operator_is_unaric = 1;
							break;
						case 'o':
							if (numbers_stack[ns_index] / M_PI == (int)(numbers_stack[ns_index] / M_PI)){
								*res = 11;
								return 0;
							}
							numbers_stack[ns_index] = pow(tan(numbers_stack[ns_index]), -1); //////    	СДЕЛАТЬ ЛОГАРИФМ!!!!!!!!!!!!!
							operator_is_unaric = 1;
							break;
						case 'l':
						/*
							if (numbers_stack[ns_index] <= 0){
								return LOG_NOT_EXIST;
							}*/
							numbers_stack[ns_index] = log(numbers_stack[ns_index]); //////    	СДЕЛАТЬ ЛОГАРИФМ!!!!!!!!!!!!!
							operator_is_unaric = 1;
							break;
						case '^':
							if ((abs(numbers_stack[ns_index]) < 1) && (numbers_stack[ns_index - 1] < 0)){
								*res = 11;
								return 0;
							}
							//if (!par_end_flag) printf("%.2f^%.2f=", numbers_stack[ns_index-1], numbers_stack[ns_index]);
							numbers_stack[ns_index - 1] = pow(numbers_stack[ns_index - 1], numbers_stack[ns_index]);
							//if (!par_end_flag) printf("%.2f* ", numbers_stack[ns_index-1]);
							break;
						default:
							break;

					}

					if (operators_stack[os_index] == '('){
						memset(operators_stack + os_index, '\0', 1);
						os_index--;
						//printf("%.2f ", numbers_stack[ns_index]);
						break;
					}

					if (!operator_is_unaric){
						memset(numbers_stack + ns_index, '\0', 1);
						ns_index--;
					}
					//printf(" = %.3f ", numbers_stack[ns_index]);
					//printf("%d", os_index);

					memset(operators_stack + os_index, '\0', 1);
					os_index--;
					if (operators_stack[os_index] == '('){
						memset(operators_stack + os_index, '\0', 1);
						os_index--;

						//printf("%.2f (%d)", numbers_stack[ns_index], ns_index);
						break;
					}
					if (os_index <= -1){
						break;
					}
					operator1 = operators_stack[os_index];
				}

				if (par_end_flag){
					par_end_flag = 0;
				}
				else operators_stack[++os_index] = operator2;
				//printf(" %c ", operators_stack[os_index]);
			}
		}
	}

	//printf("| ");
	*res = numbers_stack[0]; // Вывод результата

	return 0;
}

int priority(char opr){
	switch (opr){
		case '+':
			return 1;
		case '-':
			return 1;
		case '*':
			return 2;
		case '/':
			return 2;
		case 's': // sin
			return 3;
		case 'c': // cos
			return 3;
		case 't': // tan
			return 3;
		case 'o': // cotan
			return 3;
		case 'l': // log (натуральный логарифм)
			return 3;
		case '^':
			return 4;
		case '(':
		  	return 5;
		default:
			return 0;
	}
}
