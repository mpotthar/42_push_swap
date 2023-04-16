/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:00:00 by mpotthar          #+#    #+#             */
/*   Updated: 2023/04/16 00:00:00 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_check_if_sorted(t_list *stack)
{
	if (!stack)
		return (false);
	while (stack->next)
	{
		if (stack->num > stack->next->num)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_bool	ft_check_occurrence(t_list *stack_a, int num)
{
	while (stack_a)
	{
		if (stack_a->num == num)
			return (false);
		stack_a = stack_a->next;
	}		
	return (true);
}
