/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forward.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:00:00 by mpotthar          #+#    #+#             */
/*   Updated: 2023/04/21 09:14:26 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sorting algorithm for forward order (stack a to stack b)
// ----------------------------------------------------------------------------
// check first spot in stack a
// if spot is new max and max of stack_b is on top -> push
// if spot is bigger than first spot in b and smaller than last spot in b->push
// if spot is new min and max of stack_b is on top -> push b and rotate b
// if spot is smaller than first spot in b and bigger than second spot in b 
// -> push and swap b
static t_bool	ft_fst_spot(t_list **stack_a, t_list **stack_b, t_vars *vars)
{
	int	spot;

	spot = (*stack_a)->num;
	if ((spot > vars->max_b && (*stack_b)->num == vars->max_b)
		|| (spot > (*stack_b)->num && spot < ft_lstlast(*stack_b)->num))
		ft_push_b(stack_a, stack_b, vars);
	else if (spot < vars->min_b && (*stack_b)->num == vars->max_b)
	{
		ft_push_b(stack_a, stack_b, vars);
		ft_rotate("rb", stack_b);
	}
	else if (spot < (*stack_b)->num && spot > (*stack_b)->next->num)
	{
		ft_push_b(stack_a, stack_b, vars);
		ft_swap("sb", stack_b);
	}
	else
		return (false);
	return (true);
}

// check second spot in stack a
// if 2nd spot is new max and max of stack_b is on top -> swap a
// if 2nd spot is bigger than first spot in b and smaller than last spot in b
// -> swap a
static t_bool	ft_snd_spot(t_list **stack_a, t_list **stack_b, t_vars *vars)
{
	int	spot;

	spot = (*stack_a)->next->num;
	if ((spot > vars->max_b && (*stack_b)->num == vars->max_b)
		|| (spot > (*stack_b)->num && spot < ft_lstlast(*stack_b)->num))
		ft_swap("sa", stack_a);
	else
		return (false);
	return (true);
}

// check last spot in stack a
// if last spot is new max and max of stack_b is on top -> reverse rotate a
// if last spot is bigger than first spot in b and smaller than last spot in b
// -> reverse rotate a
static t_bool	ft_last_spot(t_list **stack_a, t_list **stack_b, t_vars *vars)
{
	int	spot;

	spot = ft_lstlast(*stack_a)->num;
	if ((spot > vars->max_b && (*stack_b)->num == vars->max_b)
		|| (spot > (*stack_b)->num && spot < ft_lstlast(*stack_b)->num))
		ft_reverse_rotate("rra", stack_a);
	else
		return (false);
	return (true);
}

// check for "cheapest spot" with fewest operations in stack a and b and
// rotate a and b to that spot
static void	ft_diff_spot(t_list **stack_a, t_list **stack_b, t_vars *vars)
{
	t_list	*tmp_a;
	int		num_a;
	int		min_num_a;
	int		cnt_ops;

	tmp_a = (*stack_a);
	num_a = tmp_a->num;
	min_num_a = 1 + ft_cnt_ops_in_b(stack_b, vars, tmp_a->num);
	while (tmp_a)
	{
		cnt_ops = 1 + ft_cnt_ops_in_a(stack_a, vars, tmp_a->num)
			+ ft_cnt_ops_in_b(stack_b, vars, tmp_a->num);
		if (cnt_ops < min_num_a)
		{
			min_num_a = cnt_ops;
			num_a = tmp_a->num;
		}
		tmp_a = tmp_a->next;
	}
	ft_rotate_a(stack_a, vars, num_a);
	ft_rotate_b(stack_b, vars, (*stack_a)->num);
}

// main function for sorting stack a to stack b
// calls all forward algo functions
void	ft_sort_forward(t_list **stack_a, t_list **stack_b, t_vars *vars)
{
	while (vars->len_a > 3 && vars->len_b < 2)
		ft_push_b(stack_a, stack_b, vars);
	if (vars->len_b == 2 && (*stack_b)->num < (*stack_b)->next->num)
		ft_rotate("rb", stack_b);
	while (vars->len_a > 3)
	{
		if (ft_fst_spot(stack_a, stack_b, vars) == false)
		{
			if (ft_snd_spot(stack_a, stack_b, vars) == false)
				if (ft_last_spot(stack_a, stack_b, vars) == false)
					ft_diff_spot(stack_a, stack_b, vars);
			ft_push_b(stack_a, stack_b, vars);
		}
	}
	if (vars->len_a == 2)
		if ((*stack_a)->num > (*stack_a)->next->num)
			ft_swap("sa", stack_a);
	if (vars->len_a == 3)
		ft_order_last_three_spots(stack_a, vars);
}
