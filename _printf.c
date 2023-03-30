#include "main.h"
#include <stdio.h>

/**
 * _printf - Prints a formatted string to the standard output stream.
 *
 * @format: A string containing format specifiers.
 *
 * Return: The number of characters printed, or -1 on failure.
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	int (*f)(va_list args);
	va_list args;

	/* Initialize variable argument list */
	va_start(args, format);

	/* Check if format string is not NULL */
	if (format != NULL)
	{
		/* Loop through format string */
		while (format[i] != '\0')
		{
			/* Check if current character is a format specifier */
			if (format[i] == '%')
			{
				/* Check if next character is a valid format specifier */
				if (format[i + 1] != '\0')
				{
					/* Get function pointer for corresponding format specifier */
					f = get_op_func(format[i + 1]);
					if (f != NULL)
					{
						/* Call function and update count and index */
						count += f(args), i += 2;
						continue;
					}
					else
					{
						/* Print literal '%' character and update count and index */
						_putchar('%'), i++;
						count++;
						continue;
					}
				}
				/* Return -1 if '%' is the last character in the format string */
				if (format[i + 1] == '\0')
					return (-1);
			}
			/* Print literal character and update count and index */
			_putchar(format[i]);
			i++, count++;
		}
		/* Return count if end of format string is reached */
		if (format[i] == '\0')
			return (count);
	}
	else
		/* Return -1 if format string is NULL */
		return (-1);

	/* Clean up variable argument list */
	va_end(args);

	/* Return 0 if no characters were printed */
return (0);
}
