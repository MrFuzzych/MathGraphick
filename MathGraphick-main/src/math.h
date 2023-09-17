/**
 * @brief Функция обработки математической функции.
 * @param func функция в виде строки.
 * @param values_arr массив значений функции.
 * @return код ошибки.
 */
int create_values_arr(char func[], float values_arr[]);
 
int parse(char func[], float* res, float x);

int priority(char opr);




