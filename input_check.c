/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:24:52 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/10 16:53:43 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Checks for duplated numbers. Returns: 1 if a duplicate is found, 0 if not.*/
int	is_duplicate(t_stack *stack_a)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = stack_a;
	while (tmp1)
	{
		tmp2 = tmp1->next;
		while (tmp2)
		{
			if (tmp1->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

/*Checks if all str generated after spliting the input (argv) are numbers.
 * Returns: 1 if true, 0 if not.*/
long	input_is_ok(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '-' || str[i] == '+') && (ft_strlen(str) > 1))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/*Assigns an index to each element in the stack to have an idea of the order
 * that each element should have from the highest number (stack_size) to the
 * lower (1).*/
void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value_ref;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value_ref = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value_ref && ptr->index == 0)
			{
				value_ref = ptr->value;
				highest = ptr;
				ptr = ptr->next;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
