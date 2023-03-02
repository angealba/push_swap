/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_position.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:21:52 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/02 20:29:41 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (tmp_a->index < target_index)
		{
			t_indx = tmp_a->index;
			t_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (t_pos);
}

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
