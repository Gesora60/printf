#include "main.h"

/**
 * _printf - implementation of the inbuilt printf
 * @format: the format specifier
 * Return: the formated string
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;

	while (*format)
	{
		if (*format != '%')
		{
			format++;
			_putchar(*format);
			format++;
		}
		else
		{
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				while (*string != '\0')
				{
					_putchar(*s);
					s++;
					count++;
				}
			}
			else
			{
				_putchar('%');
				count++;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}

