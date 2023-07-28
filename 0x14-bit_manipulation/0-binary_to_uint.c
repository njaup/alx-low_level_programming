#include "main.h"
#include <stddef.h>
#include <stdlib.h>

/**
 * binary_to_uint -  takes a binary string as input and converts
 * it to an unsigned integer
 * @b: A pointer to a constant character string
 * Return: result
 */
unsigned int binary_to_uint(const char *b)
{
	size_t len = 0;
	unsigned int result = 0;
	size_t i;

	if (b == NULL)
		return (0);

	while (b[len] != '\0')
	{
		if (b[len] != '0' && b[len] != '1')
		{
			return (0);
		}
		len++;
	}
	for (i = 0; i < len; i++)
	{
		result = (result << 1) + (b[i] - '0');
	}
	return (result);
}
/**
 * unit_to_str - takes an unsigned integer as input and converts it to
 * a dynamically allocated string representation
 * @num: converted to a string representation
 * Return: str
 */
char *uint_to_str(unsigned int num)
{
	unsigned int temp = num;
	size_t len = 0;

	if (num == 0)
	{
		char *str = (char *)malloc(2);

		if (str != NULL)
		{
			str[0] = '0';
			str[1] = '\0';
		}
		return (str);
	}
	while (temp > 0)
	{
		temp /= 10;
		len++;
	}
	char *str = (char *)malloc(len + 1);

	if (str != NULL)
	{
		str[len] = '\0';

		while (num > 0)
		{
			str[--len] = '0' + (num % 10);
			num /= 10;
		}
	}
	return (str);
}
/**
 * print_result - takes a binary string as input,
 * converts it to an unsigned integer
 * @binary_str: A pointer to a constant character string
 */
void print_result(const char *binary_str)
{
	unsigned int result = binary_to_uint(binary_str);
	char *result_str = uint_to_str(result);

	if (result_str != NULL)
	{
		char *p = result_str;

		while (*p != '\0')
		{
			_putchar(*p);
			p++;
		}
		_putchar('\n');
		free(result_str);
	}
}
/**
 * main - entry point of the program
 * Return: 0
 */
int main(void)
{
	const char *binary_str1 = "1101";
	const char *binary_str2 = "10101010";
	const char *invalid_str = "12345";
	const char *null_str = NULL;

	print_result(binary_str1);
	print_result(binary_str2);
	print_result(invalid_str);
	print_result(null_str);

	return (0);
}
