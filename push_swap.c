/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:17:11 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/08 20:44:41 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Checks if the stack is sorted. Returns 1 if true, 0 if not.*/
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/*Evaluates the sorting case depending on the stack_size.*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		play_sa(stack_a);
	else if (stack_size == 3 && !is_sorted(*stack_a))
		short_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		long_sort(stack_a, stack_b);
	else
		return ;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;

	if (argc < 2)
		return (0);
	if (!input_check(argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_b = NULL;
	stack_a = fill_stack(argc, argv);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	/*push_swap(&stack_a, &stack_b, stack_size);
	free;*/
	printf("is sorted? %d\n", is_sorted(stack_a));
	/*while (stack_a)
	{
		printf("value: %d, index: %d\n", stack_a->value, stack_a->index);
		stack_a = stack_a->next;
	}*/
	/*while(stack_a != NULL)
	{
		play_pb(&stack_a, &stack_b);
	}*/
	/*while(stack_b)
	{
		printf("value_b: %d, index_b: %d\n", stack_b->value, stack_b->index);
		stack_b = stack_b->next;
	}*/
	/*play_rra(&stack_a);*/
	push_swap(&stack_a, &stack_b, stack_size);
	while (stack_a)
	{
		printf("value2: %d, index2: %d\n", stack_a->value, stack_a->index);
		stack_a = stack_a->next;
	}
	return (0);
}
