/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_forward.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:00:00 by mpotthar          #+#    #+#             */
/*   Updated: 2023/04/21 10:05:50 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// count rotations needed to rotate stack a to num
int	ft_cnt_ops_in_a(t_list **stack_a, t_vars *vars, int num)
{
	int		cnt;
	t_list	*tmp_a;

	cnt = 0;
	tmp_a = *stack_a;
	while (tmp_a->next)
	{
		if (tmp_a->num == num)
		{
			if (vars->len_a - cnt > cnt)
				return (cnt);
			else
				return (vars->len_a - cnt);
		}
		cnt++;
		tmp_a = tmp_a->next;
	}
	return (1);
}

// count rotations of stack b needed to insert num
int	ft_cnt_ops_in_b(t_list **stack_b, t_vars *vars, int num_a)
{
	int		cnt;
	t_list	*tmp_b;

	cnt = 1;
	tmp_b = *stack_b;
	while (tmp_b)
	{
		if ((tmp_b->next && tmp_b->num > num_a && tmp_b->next->num < num_a)
			|| (num_a < vars->min_b && tmp_b->num == vars->max_b)
			|| (num_a > vars->max_b && tmp_b->num == vars->max_b))
		{
			if (vars->len_b - cnt > cnt)
				return (cnt);
			if ((num_a < vars->min_b && tmp_b->num == vars->max_b)
				|| (num_a > vars->max_b && tmp_b->num == vars->max_b))
				return (vars->len_b - --cnt);
			else
				return (vars->len_b - cnt);
		}
		cnt++;
		tmp_b = tmp_b->next;
	}
	return (0);
}

// calculate shortest path to rotate (ra or rra)
void	ft_rotate_a(t_list **stack_a, t_vars *vars, int num_a)
{
	int		cnt;
	t_list	*tmp_a;

	cnt = 0;
	tmp_a = *stack_a;
	while (tmp_a->next)
	{
		if (tmp_a->num == num_a)
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
}

// rotates stack b to insert new min or max
static void	ft_rotate_min_max(t_list **stack_b, t_vars *vars, int cnt)
{
	if (vars->len_b - cnt > cnt)
		while (--cnt >= 0)
			ft_rotate("rb", stack_b);
	else
	{
		cnt--;
		while (++cnt <= vars->len_b)
			ft_reverse_rotate("rrb", stack_b);
	}
}

// rotates stack b to insert num
void	ft_rotate_b(t_list **stack_b, t_vars *vars, int num_a)
{
	int		cnt;
	t_list	*tmp_b;

	cnt = 1;
	tmp_b = *stack_b;
	while (tmp_b)
	{
		if (tmp_b->next && tmp_b->num > num_a && tmp_b->next->num < num_a)
		{
			if (vars->len_b - cnt > cnt)
				while (--cnt >= 0)
					ft_rotate("rb", stack_b);
			else
				while (++cnt <= vars->len_b)
					ft_reverse_rotate("rrb", stack_b);
		}
		if ((num_a < vars->min_b && tmp_b->num == vars->max_b)
			|| (num_a > vars->max_b && tmp_b->num == vars->max_b))
			ft_rotate_min_max(stack_b, vars, cnt);
		cnt++;
		tmp_b = tmp_b->next;
	}
}
