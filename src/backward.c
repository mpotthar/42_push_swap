/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backward.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:00:00 by mpotthar          #+#    #+#             */
/*   Updated: 2023/04/20 15:25:22 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// last step: rotate the stack to the minimum number
void	ft_order_ascending(t_list **stack_a, t_vars *vars)
{
	int		cnt;
	t_list	*tmp_a;

	vars->len_a = ft_lstsize(*stack_a);
	cnt = 0;
	tmp_a = *stack_a;
	if (tmp_a->num == vars->min_a)
		return ;
	while (tmp_a->num != vars->min_a)
	{
		cnt++;
		tmp_a = tmp_a->next;
	}
	if (vars->len_a - cnt > cnt)
		while (--cnt >= 0)
			ft_rotate("ra", stack_a);
	else
		while (++cnt <= vars->len_a)
			ft_reverse_rotate("rra", stack_a);
}

// rotate stack_a (shortest) and push from b to a
void	ft_sort_backward(t_list **stack_a, t_list **stack_b, t_vars *vars)
{
	int		cnt;
	t_list	*tmp_a;

	tmp_a = *stack_a;
	vars->len_a = ft_lstsize(*stack_a);
	cnt = 1;
	while (tmp_a->next)
	{
		if ((tmp_a->num < (*stack_b)->num && tmp_a->next->num > (*stack_b)->num)
			|| ((*stack_b)->num < vars->min_a && tmp_a->num == vars->max_a)
			|| ((*stack_b)->num > vars->max_a && tmp_a->num == vars->max_a))
		{
			if (vars->len_a - cnt > cnt)
				while (--cnt >= 0)
					ft_rotate("ra", stack_a);
			else
				while (++cnt <= vars->len_a)
					ft_reverse_rotate("rra", stack_a);
			break ;
		}
		cnt++;
		tmp_a = tmp_a->next;
	}
	ft_push_a(stack_a, stack_b, vars);
}

// sort last three numbers in stack_a
void	ft_order_last_three_spots(t_list **stack_a, t_vars *vars)
{
	t_bool	valid;

	valid = false;
	while (valid == false)
	{
		if ((*stack_a)->num < (*stack_a)->next->num
			&& (*stack_a)->next->num < (*stack_a)->next->next->num)
			valid = true;
		else if ((*stack_a)->num < (*stack_a)->next->num
			&& (*stack_a)->next->num > (*stack_a)->next->next->num)
			ft_reverse_rotate("rra", stack_a);
		else if ((*stack_a)->num > (*stack_a)->next->num
			&& (*stack_a)->num < (*stack_a)->next->next->num)
			ft_swap("sa", stack_a);
		else if ((*stack_a)->num > (*stack_a)->next->num
			&& (*stack_a)->num > (*stack_a)->next->next->num)
			ft_rotate("ra", stack_a);
	}
	vars->len_a = ft_lstsize(*stack_a);
	vars->min_a = (*stack_a)->num;
	vars->max_a = ft_lstlast(*stack_a)->num;
}
