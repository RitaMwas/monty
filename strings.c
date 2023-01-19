#include "monty.h"

/**
 * _strcpy - Entry point
 *
 * Description: Makes a copy of a string
 * @dest: Address of buffer to copy string to
 * @src: Address of string to be copied
 *
 * Return: the pointer to dest. Otherwise NULL
 */
char *_strcpy(char *dest, const char *src)
{
	unsigned int i;

	if (src == NULL || dest == NULL)
		return (NULL);

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - Entry point
 *
 * Description: Creates a copy of a gien string
 * @str: string to copy
 *
 * Return: new string identical to str. Otherwise NULL
 */
char *_strdup(const char *str)
{
	unsigned int length;
	char *result;

	if (str == NULL)
		return (NULL);

	/* allocate space for new string */
	length = strlen(str);
	result = malloc(sizeof(char) * (length + 1));
	if (result == NULL)
		return (NULL);

	/* copy contents of str into new string */
	return (_strcpy(result, str));
}

/**
 * _strtok - Entry point
 *
 * Description: tokenizes a gien string using a given delimiter
 * @str: string
 * @delim: delimiter
 * Return: pointer to next token. Otherwise NULL
 */
char *_strtok(char *str, const char *delim)
{
	char c;
	int found_char = 0;
	char *start;
	static char *current;

	start = (str ? str : current);

	if (str)
		current = str;

	if (delim == NULL || *current == '\0')
		return (NULL);

	c = delim[0];

	while (*current == c) /* ignore separators at beginning */
	{
		start++;
		current++;
	}

	while (*current)
	{
		if (*current == c && found_char) /* found a delimiter */
		{
			*current = '\0';
			current++;
			break;
		}

		found_char = 1;
		current++;
	}

	while (*current && *current == c) /* ignore separators at the end */
		current++;

	return (strlen(start) ? start : NULL);
}

/**
 * is_valid_int - Entry point
 *
 * Description: Checks if a given string is a valid integer
 * @str: string
 * Return: 1 if str is a valid integer. 0 otherwise
 */
int is_valid_int(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i]; i++)
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] != '-' || i != 0)
				return (0);
		}
	}

	return (1);
}
