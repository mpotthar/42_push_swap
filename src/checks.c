/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:00:00 by mpotthar          #+#    #+#             */
/*   Updated: 2023/04/17 13:22:40 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if the string is a number
t_bool	ft_check_char_occurrence(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}

// checks if the number is already in the stack
t_bool	ft_check_double_occurrence(t_list *stack_a, int num)
{
	while (stack_a)
	{
		if (stack_a->num == num)
			return (false);
		stack_a = stack_a->next;
	}		
	return (true);
}

// checks if the stack is already sorted in ascending order
t_bool	ft_check_ascending_order(t_list *stack)
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
