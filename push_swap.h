/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: analbarr <analbarr@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 19:56:52 by analbarr          #+#    #+#             */
/*   Updated: 2023/03/01 19:51:16 by analbarr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/*input*/
int			input_check(char **argv);

/*fill stack*/
t_stack		*fill_stack(int argc, char **argv);
t_stack		*new_stack(int value);
t_stack		*get_bottom(t_stack *stack);
t_stack		*get_one_before_bottom(t_stack *stack);
void		add_bottom_stack(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack *stack);
void		assign_index(t_stack *stack_a, int stack_size);

/*Sorting*/
int			is_sorted(t_stack *stack);
void		short_sort(t_stack **stack);

/*utils*/
long int	ft_atoi(const char *str);
void		free_stack(t_stack **stack);
void		error_exit(t_stack **stack_a, t_stack **stack_b);

/*moves*/
void		play_sa(t_stack **stack_a);
void		play_sb(t_stack **stack_b);
void		play_ss(t_stack **stack_a, t_stack **stack_b);
void		play_ra(t_stack **stack_a);
void		play_rb(t_stack **stack_b);
void		play_rr(t_stack **stack_a, t_stack **stack_b);
void		play_rra(t_stack **stack_a);
void		play_rrb(t_stack **stack_b);
void		play_rrr(t_stack **stack_a, t_stack **stack_b);
void		play_pa(t_stack **stack_a, t_stack **stack_b);
void		play_pb(t_stack **stack_a, t_stack **stack_b);

/*push_swap*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);
#endif
