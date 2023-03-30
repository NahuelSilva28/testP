#include "main.h"

/**
* _strlen - calculates the length of a string
* @s: the string to calculate the length of
*Return: the length of the string
*/
int _strlen(char *s)
{
int len = 0;

while (s && *(s++))
len++;
return (len);
}

/**
*print_CHAR - prints a character
*@args: list of arguments to the function
*Return: the number of characters printed (always 1)
*/
int print_CHAR(va_list args)
{
char c = va_arg(args, int);

_putchar(c);
return (1);
}

/**
*print_STR - prints a string
*@args: list of arguments to the function
*Return: the number of characters printed
*/
int print_STR(va_list args)
{
char *str = va_arg(args, char *);
int len = 0;

if (!str)
str = "(null)";
while (str[len])
_putchar(str[len++]);
return (len);
}
/**
*print_INT - Prints an integer
*
*@args: A va_list containing the integer to print
*
*Return: The number of characters printed
*/
int print_INT(va_list args)
{
unsigned int decimal, digit, natural;
int n = va_arg(args, int);
int count = 0;

if (n == 0)
{
_putchar('0');
return (1);
}
else if (n < 0)
{
_putchar('-');
natural = -n;
count++;
}
else
natural = n;

decimal = 1;
while (decimal <= natural / 10)
decimal *= 10;

while (decimal > 0)
{
digit = natural / decimal;
_putchar(digit + '0');
count++;
natural %= decimal;
decimal /= 10;
}

return (count);
}

/**
*print_DEC - prints a decimal (base 10) integer
*@args: list of arguments to the function
*Return: the number of digits printed
*/
int print_DEC(va_list args)
{
unsigned int num, digit, n = va_arg(args, int);
int count = 0;

if (n == 0)
{
_putchar('0');
return (1);
}
if (n < 0)
{
_putchar('-');
count++;
num = -n;
}
else
num = n;
for (digit = 1; digit <= num / 10; digit *= 10)
;
while (digit != 0)
{
_putchar(num / digit + '0');
num %= digit;
digit /= 10;
count++;
}
return (count);
}


/**
*print_PER - prints a percent character
*@args: list of arguments to the function (unused)
*Return: always 1 (because only one character is printed)
*/
int print_PER(va_list args)
{
(void)args;
_putchar('%');
return (1);
}
