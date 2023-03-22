/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:17:11 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/22 12:25:45 by analbarr         ###   ########.fr       */
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

/*Takes input (argv) as a string, splits it into an array of strings, checks 
 * if each string is valid according to input parameters and converts it to an 
 * integer. Adds it as a new element to the stack_a.*/
void	get_numbers(char *argv, t_stack **stack_a)
{
	char		**input;
	long int	num;
	int			i;

	input = ft_split(argv, ' ');
	i = 0;
	while (input[i] != '\0')
	{
		if (input_is_ok(input[i]))
		{
			num = ft_atoi(input[i]);
			if (num > INT_MAX || num < INT_MIN)
				error_exit(stack_a, NULL);
			add_stack(stack_a, new_stack(num));
		}
		else
			error_exit(NULL, NULL);
		free(input[i]);
		i++;
	}
	free(input);
}

/*Evaluates the sorting case depending on the stack_size.*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		play_sa(stack_a);
	else if (stack_size == 3)
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
	int		i;

	if (argc < 2)
		return (0);
	i = 1;
	stack_a = NULL;
	stack_b = NULL;
	while (i < argc)
	{
		get_numbers(argv[i], &stack_a);
		i++;
	}
	if (is_duplicate(stack_a))
		error_exit(&stack_a, NULL);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

/*printf("is sorted? %d\n", is_sorted(stack_a));
	while (stack_a != NULL)
	{
		printf("value: %d, index: %d\n", stack_a->value, stack_a->index);
		stack_a = stack_a->next;
	}
	while(stack_a != NULL)
	{
		play_pb(&stack_a, &stack_b);
	}
	while(stack_b)
	{
		printf("value_b: %d, index_b: %d\n", stack_b->value, stack_b->index);
		stack_b = stack_b->next;
	}
	play_rra(&stack_a);
	while (stack_a)
	{
		printf("value2: %d, index2: %d\n", stack_a->value, stack_a->index);
		stack_a = stack_a->next;
	//system("leaks push_swap");
	}*/
