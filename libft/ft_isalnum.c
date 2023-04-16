/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 09:58:41 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/11 07:47:59 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The ft_isalnum() function tests for any character for which ft_isalpha(3) or
// ft_isdigit(3) is true.
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) == 1 || ft_isdigit(c) == 1)
		return (1);
	return (0);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%d\n", ft_isalnum('-'));	
// }