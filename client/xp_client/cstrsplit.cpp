
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


void		free2d(void **array)
{
	int		i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}
}

int			arraycount(char **array)
{
	int		i = 0;

	while (array[i])
		i++;
	return (i);
}

char 		**arraypush(char **array, char *str)
{
	char	**newarray;

	if (array == NULL)
	{
		newarray = (char **)malloc(sizeof(char*) * 2);
		newarray[0] = strdup(str);
		newarray[1] = NULL;
	}
	else
	{
		int i = 0;
		newarray = (char **)malloc(sizeof(char *) * (arraycount(array) + 2));
		while (array[i])
		{

			newarray[i] = strdup(array[i]);
			i++;
		}
		newarray[i] = strdup(str);
		newarray[++i] = NULL;
//		free2d((void**)array);
	}
	return (newarray);
}

char	*charpush(char *str, char c)
{
	char	*newstr;

	if (str == NULL)
	{
		newstr = (char*)malloc(sizeof(char) * 2);
		newstr[0] = c;
		newstr[1] = '\0';
	}
	else
	{
		int i = 0;
		newstr = (char *)malloc(sizeof(char) * strlen(str) + 2);
		while (str[i])
		{
			newstr[i] = str[i];
			i++;
		}
		newstr[i] = c;
		newstr[++i] = '\0';
		free(str);
	}
	return (newstr);
}

char		**cstrsplit(const char *str, char delim)
{
	char	**newarr;
	int		i;
	char	*newstr;

	i = 0;
	newarr = NULL;
	newstr = NULL;
	while (str[i])
	{
		if (str[i] == delim)
		{
			newarr = arraypush(newarr, newstr);
			free(newstr);
			newstr = NULL;
		}
		else
		{
			newstr = charpush(newstr, str[i]);
		}
		i++;
	}
	newarr = arraypush(newarr, newstr);
	return (newarr);
}
/*
int	main(void)
{
	char hello[] = "hello world";
	char **arr = cstrsplit(hello, ' ');
	int i = 0;
	while (arr[i])
	{
		printf("arr is %s\n", arr[i]);
		i++;
	}
}
*/





