/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:26:06 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/11 07:48:02 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_isalpha() function tests for any character for which isupper(3) or
// islower(3) is true.
int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%d\n", ft_isalpha('-'));	
// }