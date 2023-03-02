/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_moves.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:11:39 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/01 15:07:58 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Reverse rotate: Shift down all elements of a stack by 1.
The last element becomes the first one*/
static void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;
	t_stack	*new_tail;

	tmp = *stack;
	tail = get_bottom(*stack);
	new_tail = get_one_before_bottom(*stack);
	*stack = tail;
	(*stack)->next = tmp;
	new_tail->next = NULL;
}

/*Reverse rotates stack_a. Writes rra */
void	play_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

/*Reverse rotates stack_b. Writes rrb */
void	play_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

/*Reverse rotates stack_a and stack_b. Writes rrr */
void	play_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
