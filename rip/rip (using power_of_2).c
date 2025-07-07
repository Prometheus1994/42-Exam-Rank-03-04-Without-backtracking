#include <stdio.h>

int ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}

int power_of_2(int exponent)
{
	int i = 0;
	int power = 1;
	while (i < exponent)
	{
		power *= 2;
		i++;
	}
	return power;
}

int is_balanced(char *str)
{
	int balance = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '(')
			balance++;
		if (str[i] == ')')
			balance--;
		if (balance < 0)
			return 0;
		i++;
	}
	if (balance == 0)
		return 1;
	return 0;
}

int main(int argc, char **argv)
{
	char array[ft_strlen(argv[1]) + 1];
	array[ft_strlen(argv[1])] = '\0';
	int min = ft_strlen(argv[1]) / 2 + 1;
	int i = 0;
	while (i < power_of_2(ft_strlen(argv[1]) / 2 + 1))
	{
		int j = 0;
		while (argv[1][j] != '\0')
		{
			array[j] = argv[1][j];
			j++;
		}
		int underscore_nbr = 0;
		j = 0;
		while (j < ft_strlen(argv[1]) / 2 + 1)
		{
			if (i / power_of_2(j) % 2)
			{
				array[j * 2] = '_';
				underscore_nbr++;
			}
			j++;
		}
		if (is_balanced(array) && underscore_nbr < min)
			min = underscore_nbr;
		i++;
	}
	i = 0;
	while (i < power_of_2(ft_strlen(argv[1]) / 2 + 1))
	{
		int j = 0;
		while (argv[1][j] != '\0')
		{
			array[j] = argv[1][j];
			j++;
		}
		int underscore_nbr = 0;
		j = 0;
		while (j < ft_strlen(argv[1]) / 2 + 1)
		{
			if (i / power_of_2(j) % 2)
			{
				array[j * 2] = '_';
				underscore_nbr++;
			}
			j++;
		}
		if (is_balanced(array) && underscore_nbr == min)
			puts(array);
		i++;
	}
}