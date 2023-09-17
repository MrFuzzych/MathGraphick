#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "error_proc.h"

// Функция для поиска слова в файле
int get_function(char func[], float values_arr[], int * func_found) {
    // Открытие файла для чтения

    int comp_flag = 1;

    FILE* file = fopen("Saves.txt", "r");
    if (file == NULL) {
        return FILE_ERROR;
    }
    char line[500];

    // Поиск функции в файле
    while (!feof(file)) {
        comp_flag = 1;
        fgets(line, 500, file);
        for (int i = 0; line[i] != '\0'; i++){
            //if (1) printf("%c", func[i]);
            if (line[i] != func[i]){
                comp_flag = 0;
                break;
            }
        }
        if (comp_flag) {
            int count = 0;
            *func_found = 1;
                while (count != 41) {
                    fscanf(file, "%f", values_arr + count);
                    count++;
                }
            fclose(file);
            return 0;
        }
    }

    fclose(file);
    return 0;
}

// Функция для записи слова в файл
int save_function(char func[], float values_arr[]) {
    // Открытие файла для добавления текста в конец
    FILE* file = fopen("Saves.txt", "a");
    if (file == NULL) {
        return FILE_ERROR;
    }

    // Запись слова в файл
    fprintf(file, "%s\n", func);
    for(int i = 0; i < 41; i++){
      fprintf(file, "%.3f ", values_arr[i]);
    }
    fprintf(file, "\n");

    fclose(file);

    return 0;
}

