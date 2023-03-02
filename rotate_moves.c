/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:40:09 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/01 15:07:54 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Shift up all elements of a stack by 1. 
 * The first element becomes the last one.*/
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*tail;

	tmp = *stack;
	*stack = (*stack)->next;
	tail = get_bottom(*stack);
	tail->next = tmp;
	tmp->next = NULL;
}

/* Shift up all elements of stack_a by 1.  Writes ra.*/
void	play_ra(t_stack **stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

/* Shift up all elements of stack_b by 1. Writes rb.*/
void	play_rb(t_stack **stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}

/* Shift up all elements of stack_a and stack_b by 1. Writes rr.*/
void	play_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	write(1, "rr\n", 3);
}
