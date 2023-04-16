/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:23:09 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/11 07:49:42 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The ft_strlen() function computes the length of the string s.  The 
// ft_strnlen() function attempts to compute the length of s, but never 
// scans beyond the first maxlen bytes of s.
size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }