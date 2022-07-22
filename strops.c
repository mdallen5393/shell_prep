#include "main.h"

/*
int main(void)
{
	char *s1 = "ABC";
	char *s2 = "ABD";
	char *s3 = "ABB";
	char *s4 = "ABZ";

	printf("strcmp test ['%s':'%s'] %d\n", s1, s2, _strcmp(s1, s2));
	printf("strcmp test ['%s':'%s'] %d\n", s2, s1, _strcmp(s2, s1));
	printf("strcmp test ['%s':'%s'] %d\n", s1, s1, _strcmp(s1, s1));
	printf("strncmp test 2['%s':'%s'] %d\n", s1, s3, _strncmp(s1, s3, 2));
	printf("strncmp test 3['%s':'%s'] %d\n", s1, s4, _strncmp(s1, s4, 3));
	printf("strncmp test 4['%s':'%s'] %d\n", s1, s4, _strncmp(s1, s4, 4));
}
*/


char *strcpycat(char *str1, char *str2)
{
	char *newStr;
	int l1 = _strlen(str1);
	int l2 = _strlen(str2);
	int i, j;

	newStr = malloc(sizeof(*newStr)*(l1 + l2 + 1));

	for (i = 0; i < l1; i++)
		newStr[i] = str1[i];

	for (j = 0; j < l2; j++)
	{
		newStr[i] = str2[j];
		i++;
	}

	newStr[i] = '\0';

	return (newStr);
}

int _strlen(const char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}

/**
 * _strcmp - compares two strings
 * @s1: first string
 * @s2: second string
 * Return: 0 if strings are equal, or difference if not equal.
 */
int _strcmp(const char *s1, const char *s2)
{
	int diff;
	int i;

	diff = 0;
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i])
		{
			diff = s1[i] - s2[i];
			break;
		}
		i++;
	}

	return (diff);
}

int _strncmp(const char *s1, const char *s2, size_t n)
{
	int diff;
	size_t i;

	diff = 0;
	i = 0;
	while (s1[i])
	{
		if (s1[i] != s2[i] || i == n - 1)
		{
			diff = s1[i] - s2[i];
			break;
		}
		i++;
	}

	return (diff);
}
