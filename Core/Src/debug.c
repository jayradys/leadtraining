#include "debug.h"

extern UART_HandleTypeDef huart3;


void writeDebug(const char *buffer, uint8_t length)
{
	HAL_UART_Transmit(&huart3, (uint8_t *) buffer, length, HAL_MAX_DELAY);
}

void writeDebugString(const char *buffer)
{
	writeDebug(buffer, strlen(buffer));
}

void writeDebugFormat(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	va_list args_copy;
	va_copy(args_copy, args);
	int buff_size = vsnprintf(NULL, 0, format, args_copy);
	va_end(args_copy);

	char *buff = malloc(buff_size + 1);

	if (buff == NULL)
	{
		va_end(args);
		return;
	}

	vsnprintf(buff, buff_size + 1, format, args);
	writeDebug(buff, buff_size);
	free(buff);

	va_end(args);
}
