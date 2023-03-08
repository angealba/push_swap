/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:21:52 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/08 20:42:48 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*It assigns a position to each element in the stack to be sorted. Starts with 
 [0] in ascending order from top to bottom. */
static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/*Finds the better position in stack_a where an element from stack_b should be
 * placed considering the index of each one.*/
static int	get_target(t_stack **stack_a, int indx_b, int t_indx, int t_pos)
{
	t_stack	*tmp_a;

	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index > indx_b && tmp_a->index < t_indx)
		{
			t_indx = tmp_a->index;
			t_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (t_indx != INT_MAX)
		return (t_pos);
	tmp_a = *stack_a;
	while (tmp_a)
	{
		if (tmp_a->index < t_indx)
		{
			t_indx = tmp_a->index;
			t_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (t_pos);
}

int	get_lowest_index_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/*Assigns a target position in stack_a to each element from stack_b: the spot 
 * in A where each element of B should be placed in order to be correctly 
 * sorted. This will be used to calculate the cost of moving each element.*/
void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *stack_b;
	target_pos = 0;
	get_position(stack_a);
	get_position(stack_b);
	while (tmp_b)
	{
		target_pos = get_target(stack_a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
