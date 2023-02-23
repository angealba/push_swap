/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:24:52 by analbarr          #+#    #+#             */
/*   Updated: 2023/02/23 19:06:52 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Checks if the input argument is a number. +1, 1 and -1 are valid formats. 
 * Returns: 1 if is a number and 0 if not.*/
static int	is_number(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '+' || argv[i] == '-') && argv[i + 1] != '\0')
		i++;
	while (argv[i] && (argv[i] >= '0' && argv[i] <= '9'))
		i++;
	if (argv[i] != '\0' && (argv[i] < '0' && argv[i] > '9'))
		return (0);
	return (1);
}

/*Checks if the input argument is a 0, avoiding 0 000, +0 +000, -0 -000 ...
 *  duplicates. Returns: 1 if arg is a zero, 0 if not.*/
static int	is_zero(char *argv)
{
	int	i;

	i = 0;
	if ((argv[i] == '+' || argv[i] == '-'))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

/* Compares to input args to check if are the same or not. If a string starts
 * with "+", it is ignored and continues checking the rest of the string, in 
 * order to have, for ex, +123 == 123.
 * Returns: 0 if string match and another value if not.*/
static int	num_cmp(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

/*Checks for duplated numbers. Returns: 1 if a duplicate is found, 0 if not.*/
static int	is_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv [j])
		{
			if (j != i && num_cmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/*Previous input check to see if all args are valid numbers without duplicates.
 * Returns: 1 if args are valid, 0 if not.*/
int	input_check(char **argv)
{
	int	i;
	int	zeros;

	i = 1;
	zeros = 0;
	while (argv[i])
	{
		if (!is_number(argv[i]))
			return (0);
		zeros += is_zero(argv[i]);
		i++;
	}
	if (zeros > 1)
		return (0);
	if (is_duplicate(argv))
		return (0);
	return (1);
}
