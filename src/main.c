/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 00:00:00 by mpotthar          #+#    #+#             */
/*   Updated: 2023/04/21 13:34:23 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// writes error message to stderr
static int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

// read and checks already done, this function
// calls sorting functions, the heart of the program
static void	ft_push_swap(t_list **stack_a, t_list **stack_b, t_vars *vars)
{
	vars->len_a = ft_lstsize(*stack_a);
	vars->min_a = (*stack_a)->num;
	vars->max_a = (*stack_a)->num;
	ft_sort_forward(stack_a, stack_b, vars);
	while ((*stack_b))
		ft_sort_backward(stack_a, stack_b, vars);
	if (vars->len_a >= 3)
		ft_order_ascending(stack_a, vars);
	ft_lstclear(stack_a);
	ft_lstclear(stack_b);
	free(vars);
}

// main function
int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_vars	*vars;

	stack_b = NULL;
	if (argc < 2)
		return (0);
	else if ((argc == 2 && ft_split_input(argv[1], &stack_a) == false)
		|| (argc > 2 && ft_read_input(&stack_a, argv, 1) == false))
		return (ft_error());
	if (ft_check_ascending_order(stack_a) == true)
	{
		ft_lstclear(&stack_a);
		return (0);
	}
	vars = (t_vars *)ft_calloc(1, sizeof(t_vars));
	if (!vars)
	{
		ft_lstclear(&stack_a);
		return (1);
	}
	ft_push_swap(&stack_a, &stack_b, vars);
	return (0);
}
