/**
 * @brief Функция определения ошибки.
 * @param ecode - код ошибки.
 */
void error_value(int ecode);

enum{
	INPUT_ERR = 1,
		DIVISION_BY_ZERO,
		COT_NOT_EXIST,
		TAN_NOT_EXIST,
		LOG_NOT_EXIST,
		FILE_ERROR,

};
