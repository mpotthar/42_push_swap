/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 13:44:42 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/11 07:47:50 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	output;

	i = 0;
	sign = 1;
	output = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
		output = output * 10 + (str[i++] - '0');
	return (output * sign);
}
