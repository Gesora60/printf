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
  
  while (*format != '\0')
    {
      if (*format == '%')
	{
	  _putchar(*format);
	  count++;
	}
      else
	{
	  format++;
	  if (*format == '0') break;
	  if (*format == 'c')
	    {
	      int c = va_arg(args, int);
	      _ putchar(c);
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
	  else (*format == '%')
		 {
		   putchar('%');
		   count++;
		 }
	}
      format++;
    }
  va_end(args);
  return count;
}


