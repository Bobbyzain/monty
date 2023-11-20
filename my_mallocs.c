#include "monty.h"
/**
 * _strcmp - Function that compares two strs.
 * @string1: type str compared
 * @string2: type str compared
 * Return: 0 if string1 and string2 are equals.
 *         another value if they are different
 */
int _strcmp(char *string1, char *string2)
{
	int i;

	for (i = 0; string1[i] == string2[i] && string1[i]; i++)
		;
	if (string1[i] > string2[i])
		return (1);
	if (string1[i] < string2[i])
		return (-1);
	return (0);
}

/**
 * _sch_char - search if a char is inside a string
 * @str: string to review
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int _sch_char(char *str, char c)
{
	int cont = 0;

	while (str[cont] != '\0')
	{
		if (str[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (str[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoker - tokenizes a string depending of the delimiter
 * @str: string to cut in parts
 * @delim: delimiters
 * Return: first partition
 */
char *_strtoker(char *str, char *delim)
{
	static char *ultima;
	int i = 0, j = 0;

	if (!str)
		str = ultima;
	while (str[i] != '\0')
	{
		if (_sch_char(delim, str[i]) == 0 && str[i + 1] == '\0')
		{
			ultima = str + i + 1;
			*ultima = '\0';
			str = str + j;
			return (str);
		}
		else if (_sch_char(delim, str[i]) == 0 && _sch_char(delim, str[i + 1]) == 0)
			i++;
		else if (_sch_char(delim, str[i]) == 0 && _sch_char(delim, str[i + 1]) == 1)
		{
			ultima = str + i + 1;
			*ultima = '\0';
			ultima++;
			str = str + j;
			return (str);
		}
		else if (_sch_char(delim, str[i]) == 1)
		{
			j++;
			i++;
		}
	}
	return (NULL);
}
