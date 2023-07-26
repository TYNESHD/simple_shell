#include "shell.h"

/**
 * interactive - returns true when shell in interactive mode
 * @info: shows struct address
 *
 * Return: 1 if interactive mode, else return 0
 */

int interactive(info_t *info)
{
	return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * is_delim - checks whether character is a delimeter
 * @a: char to check
 * @delim: the delimeter string
 * Return: 1 pass, 0 if fail
 */

int is_delim(char a, char *delim)
{
	while (*delim)
		if (*delim++ == a)
			return (1);
	return (0);
}

/**
 * _isalpha - checks alphabetic character
 * @a: The input char
 * Return: 1 if c is alphabetic else return 0
 **/

int _isalpha(int a)
{
	if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no number found, convert number otherwise
 **/

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;

		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}

