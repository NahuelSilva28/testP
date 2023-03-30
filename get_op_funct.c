#include "main.h"

/**
 *get_op_func - pointer to adress where the instructions of a function
 *start (it takes a char from format, in this case our format[i + 1]),
 *and returns wether if it found a function (that takes the other parameter,
 *the list of variadic arguments), or NULL in cas if it didn't match.
 *@format: i + 1, which is the format specifier to check
 *Return: the counter from the functions passed when it matches
 */
int (*get_op_func(char format))(va_list args)
{
	fmt_t opp[] = {
		{'c', print_CHAR},
		{'s', print_STR},
		{'d', print_DEC},
		{'i', print_INT},
		{'%', print_PER},
		{'\0', NULL}
	};
	int i;

	i = 0;
	while (opp[i].type != '\0')
	{
		if (opp[i].type == format) /* mandamos format[i+1] */
		{
			return (opp[i].print_type);
		}
		i++;
	}
	return (NULL);
}

