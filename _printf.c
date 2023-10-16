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
			putchar(*format);
			count++;
		}
		else
		{
		    format++;
			if (*format == 'c')
			{
				int c = va_arg(args, int);

				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				while (*s)
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			else
			{
				putchar('%');
				count++;
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
