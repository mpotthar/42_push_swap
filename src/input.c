/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:00:00 by mpotthar          #+#    #+#             */
/*   Updated: 2023/04/17 13:23:35 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_split_input(char *string_numbers, t_list **stack_a)
{
	char	**numbers;
	t_bool	result;

	if (string_numbers[0] == '\0')
		return (false);
	numbers = ft_split(string_numbers, ' ');
	if (!numbers)
		return (false);
	if (!numbers[0])
	{
		free(numbers);
		return (false);
	}
	result = ft_read_input(stack_a, numbers, 0);
	ft_free_dbl_ptr(numbers);
	return (result);
}

static t_list	*ft_get_num(t_list **stack_a, char **numbers, int i)
{
	long int	num;
	t_list		*tmp;

	if (ft_check_char_occurrence(numbers[i]) == false)
		return (NULL);
	num = ft_atol(numbers[i]);
	if ((num == 0 && numbers[i][0] != '0')
		|| (num < INT_MIN || num > INT_MAX)
		|| ft_check_double_occurrence(*stack_a, (int) num) == false)
		return (NULL);
	tmp = ft_lstnew((int)num);
	if (!tmp)
	{
		ft_lstclear(stack_a);
		return (NULL);
	}
	return (tmp);
}

// reads the input and appends it to the stack
t_bool	ft_read_input(t_list **stack_a, char **numbers, int i)
{
	long int	num;
	t_list		*tmp;

	if (ft_check_char_occurrence(numbers[i]) == false)
		return (false);
	num = ft_atol(numbers[i]);
	if ((num == 0 && numbers[i][0] != '0') || (num < INT_MIN || num > INT_MAX))
		return (false);
	*stack_a = ft_lstnew((int)num);
	if (!(*stack_a))
		return (false);
	while (numbers[++i])
	{
		tmp = ft_get_num(stack_a, numbers, i);
		if (tmp == NULL)
		{
			ft_lstclear(stack_a);
			return (false);
		}
		ft_lstadd_back(stack_a, tmp);
	}
	return (true);
}
