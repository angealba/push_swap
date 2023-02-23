/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:47:23 by analbarr          #+#    #+#             */
/*   Updated: 2023/02/23 22:44:21 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*fill_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	num;
	int			i;

	stack_a = NULL;
	num = 0;
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_exit(&stack_a, NULL);
		if (i == 1)
			stack_a = new_stack((int)num);
		else
			add_bottom_stack(&stack_a, new_stack((int)num));
		i++;
	}
	return (stack_a);
}

/*Assigns an index to each element in the stack to have an idea of the order
 * that each element should have from the highest numer (stack_size) to the
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
				ptr->value = 1;
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
