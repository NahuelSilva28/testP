#ifndef MAIN_H
#define MAIN_H


#include <stddef.h>
#include <stdarg.h>


/**
*struct format_t - A structure defining a type and its corresponding function
*@type: The format specifier character for the argument type
*@print_type: Pointer to the function that prints the argument type
*/
typedef struct format_t
{
	char type;
	int (*print_type)(va_list args);
} fmt_t;

int _printf(const char *format, ...);
int _putchar(char c);
int print_CHAR(va_list args);
int print_STR(va_list args);
int print_DEC(va_list args);
int print_PER(va_list args);
