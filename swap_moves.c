/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:57:54 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/01 19:48:52 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Swaps the first 2 elements (top) of a stack*/
static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
}

/*Swaps the first 2 elements (top) of stack_a. Writes sa.*/
void	play_sa(t_stack **stack_a)
{
	swap(stack_a);
	write (1, "sa\n", 3);
}

/*Swaps the first 2 elements (top) of stack_b. Writes sb.*/
void	play_sb(t_stack **stack_b)
{
	swap(stack_b);
	write (1, "sb\n", 3);
}

/*Swaps the first 2 elements (top) of stack_a and of stack_b. Writes ss.*/
void	play_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	write (1, "ss\n", 3);
}
