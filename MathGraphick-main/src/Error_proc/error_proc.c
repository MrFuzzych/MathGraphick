#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include "error_proc.h"
#include "view.h"

void error_value(int ecode){
	switch (ecode){
		case INPUT_ERR:
		{
			show_error("Input error");
			break;
		}
		case DIVISION_BY_ZERO:
		{
			show_error("Division by zero");
			break;
		}
		case COT_NOT_EXIST:
		{
			show_error("Cotan does not exist");
			break;
		}
		case TAN_NOT_EXIST:
		{
			show_error("Tan does not exist");
			break;
		}
		case LOG_NOT_EXIST:
		{
			show_error("Log does not exist");
			break;
		}
		case FILE_ERROR:
		    show_error("File error");
		    break;
		default:
		{
			show_error("Unknown error");
			break;
		}
	}
}
