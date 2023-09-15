/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaiao-r <abaiao-r@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:42:17 by andrefranci       #+#    #+#             */
/*   Updated: 2023/09/15 23:13:15 by abaiao-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Funtion to check if argv is a number.
(PS: isolate test is commented at the end of file)*/
int	argv_is_number(char *argv)
{
	int	i;

	i = 0;
	if (ft_issign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] != '\0')
	{
		if (!ft_isdigit(argv[i]))
		{
			printf("argv is not a number\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/* Funtion to check if there is duplicate argv.
(PS: to test in an isolate way you can replace argv_duplicate per main)*/
int	argv_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (ft_atoll(argv[i]) == ft_atoll(argv[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* Funtion to check if argv is a integer.
It first checks the length of each argument in argv and if it is
greater than 10, it returns 0, indicating that the argument is not
a valid integer. This condition was added because if argv[i] > long integer
ft_atol could convert thar agrv[i] to a number inside the range of a integer
while it is not.*/
int	argv_is_int(char **argv)
{
	int	i;
	int	len_argv;

	i = 1;
	while (argv[i] != NULL)
	{
		len_argv = ft_strlen(argv[i]);
		if (len_argv > 10)
		{
			printf("argv is not a integer because it is > 10 digits\n");
			return (0);
		}
		if (ft_atoll(argv[i]) > 2147483647 || ft_atoll(argv[i]) < -2147483648)
		{
			printf("argv is not a integer\n");
			return (0);
		}
		i++;
	}
	return (1);
}

/* This code is a function named "check_argv" that takes an
array of strings argv as an argument. The purpose of this function
is to check if the elements of the argv array are valid.

The function starts by initializing the counter i to 1. Then it
enters a while loop that continues until the argv[i] is NULL
(i.e., it reaches the end of the argv array). Inside the while loop,
the function performs several checks:

It calls the function argv_is_number and passes argv[i] as an argument.
This function checks if the string argv[i] represents a number.

It calls the function argv_duplicate and passes argv as an argument.
This function checks if there are any duplicate elements in the argv array.

It calls the function argv_is_int and passes argv as an argument.
This function checks if the string argv[i] represents an integer.

If any of these checks return false, the function check_argv calls the function
free_arguments_vector and passes argv as an argument. This function frees the
memory occupied by the argv array. Then the function check_argv returns 0.

Finally, if all the checks return true, the function check_argv returns 1. */
int	check_argv(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i] != NULL)
	{
		if (argc == 2)
		{
			if ((argv_is_number(argv[i])) == 0 || (argv_duplicate(argv)) == 1
				|| (argv_is_int(argv)) == 0)
			{
				free_arguments_vector(argv);
				return (0);
			}
		}
		else
		{
			if ((argv_is_number(argv[i])) == 0 || (argv_duplicate(argv)) == 1
				|| (argv_is_int(argv)) == 0)
			{
				return (0);
			}
		}
		i++;
	}
	return (1);
}

/* main to test check_argv */
/* int	main(void)
{
	argv[1][] = "123";
	argv[2][] = "345";
	check_argv(&argv);
	printf("argv válido: %d", check_argv(&argv));

} */
