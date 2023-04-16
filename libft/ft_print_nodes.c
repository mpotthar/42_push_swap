/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:18:24 by mpotthar          #+#    #+#             */
/*   Updated: 2023/04/16 13:18:26 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_nodes(t_list *stack_a, t_list *stack_b)
{
	ft_printf("------------------------\n");
	ft_printf("Stack_a		Stack_b\n");
	ft_printf("------------------------\n");
	while (stack_a || stack_b)
	{
		if (stack_a && stack_b)
		{
			ft_printf("%d		%d\n", stack_a->num, stack_b->num);
			stack_a = stack_a->next;
			stack_b = stack_b->next;
		}
		else if (stack_a)
		{
			ft_printf("%d\n", stack_a->num);
			stack_a = stack_a->next;
		}
		else if (stack_b)
		{
			ft_printf("		%d\n", stack_b->num);
			stack_b = stack_b->next;
		}	
	}
}
