#include "main.h"

/**
 * _printf - implementation of the inbuilt printf
 * @format: the format specifier
 * Return:  the number of characters printed (excluding
 *the null byte used to end output to strings)
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
			_putchar(*format);
			count++;
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			else if (*format == '%')
			{
				_putchar('%');
				count++;
			}
			else if (*format == 'c')
			{
				int c = va_arg(args, int);

				_putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				char *s = va_arg(args, char *);

				while (*s)
				{
					_putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == 'i' || 'd')
			{
				int num = va_arg(args, int);
				int digits = 0;
				int temp = num;
				int digit;
				if (num < 0)
				{
					count = += _putchar('-');
					num = -num;
					temp = num;
				}
				do {
					digits++;
					temp /= 10;
				} while (temp != 0);
				while (digits > 0)
				{
					int pow10 = 1;
					int i;
					for (i = 1; i < digits; i++)
					{
						pow10 *= 10;
					}
					digit = num / pow10;
					count += _putchar(digit + '0');
					num -= digit * pow10;
					digits--;
				}
			}
		}
		format++;
	}
	va_end(args);
	return (count);
}
