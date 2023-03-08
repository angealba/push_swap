/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:11:12 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/08 20:40:58 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_b_except_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	p;
	int	r;

	stack_size = get_stack_size(*stack_a);
	p = 0;
	r = 0;
	while (stack_size > 6 && r < stack_size && p < (stack_size / 2))
	{
		if ((*stack_a)->index <= (stack_size / 2))
		{
			play_pb(stack_a, stack_b);
			p++;
		}
		else
			play_ra(stack_a);
		r++;
	}
	while ((stack_size - p) > 3)
	{
		play_pb(stack_a, stack_b);
		p++;
	}
}

static void	shift_stack(t_stack **stack_a)
{
	int	stack_size;
	int	low_pos;

	stack_size = get_stack_size(*stack_a);
	low_pos = get_lowest_index_pos(stack_a);
	if (low_pos > (stack_size / 2))
	{
		while (low_pos < stack_size)
		{
			play_rra(stack_a);
			low_pos++;
		}
	}
	else
	{
		while (low_pos > 0)
		{
			play_ra(stack_a);
			low_pos--;
		}
	}
}

void	long_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_b_except_three(stack_a, stack_b);
	short_sort(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		efficient_move(stack_a, stack_b);
	}
	if (!is_sorted(*stack_a))
		shift_stack(stack_a);
}
