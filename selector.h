#include "main.h"

/**
 * selector - selects the appropriate specifiers
 * @args: number of arguements
 * @printed: the printed characters
 * @format: the format specifier
 * Return: printed charcaters
 */

int selector(const char *format, va_list args, int count)
{
	switch (*format)
	{
	case 'c':
		_putchar(va_arg(args, int));
		count++;
		break;
	case 's':
		count = printf_string(args, count);
		break;
	case '%':
		_putchar('%');
	       count++;
		break;
	default:
		break;
	}
	return (count);
}

