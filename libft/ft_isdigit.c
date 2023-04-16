/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:53:17 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/11 07:48:07 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_isdigit() function tests for a decimal digit character.
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%d\n", ft_isdigit('-'));	
// }