#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int _putchar(char character);
int _printf(const char *format, ...);
int selector(const char *format, va_list args, int count);
int printf_string(va_list args, int count);

#endif
