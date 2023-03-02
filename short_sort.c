/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 16:50:24 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/02 13:56:15 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Returns the highest index of a stack.*/
static int	get_highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/*Sorts a stack of 3 elements in which we have 3 possible cases. The sort is
 * done by index in two or fewer moves.
 * */
void	short_sort(t_stack **stack)
{
	int	highest_index;

	highest_index = get_highest_index(*stack);
	if (is_sorted(*stack))
		return ;
	if ((*stack)->index == highest_index)
		play_ra(stack);
	else if ((*stack)->next->index == highest_index)
		play_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		play_sa(stack);
}
