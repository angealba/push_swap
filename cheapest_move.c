/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheapest_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:46:47 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/08 19:31:09 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rev_rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a < 0 && *cost_b < 0)
	{
		play_rrr(a, b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	rotate_both(t_stack **a, t_stack **b, int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		play_rr(a, b);
		(*cost_a)--;
		(*cost_b)--;
	}
}

static void	rotate_a(t_stack **a, int *cost_a)
{
	while (*cost_a)
	{
		if (*cost_a < 0)
		{
			play_rra(a);
			(*cost_a)++;
		}
		else if (*cost_a > 0)
		{
			play_ra(a);
			(*cost_a)--;
		}
	}
}

static void	rotate_b(t_stack **b, int *cost_b)
{
	while (*cost_b)
	{
		if (*cost_b < 0)
		{
			play_rrb(b);
			(*cost_b)++;
		}
		if (*cost_b > 0)
		{
			play_rb(b);
			(*cost_b)--;
		}
	}
}

void	cheapest_move(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a < 0 && cost_b < 0)
		rev_rotate_both(a, b, &cost_a, &cost_b);
	else if (cost_a > 0 && cost_b > 0)
		rotate_both(a, b, &cost_a, &cost_b);
	rotate_a(a, &cost_a);
	rotate_b(b, &cost_b);
	play_pa(a, b);
}
