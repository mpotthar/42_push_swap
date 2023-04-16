/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 12:38:11 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/11 07:48:57 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The ft_memset() function writes len bytes of value c (converted to an
// unsigned char) to the string b.
void	*ft_memset(void *b, int c, size_t n)
{
	size_t			i;
	unsigned char	*pointer;

	i = 0;
	pointer = (unsigned char *)b;
	while (i < n)
		pointer[i++] = c;
	return (b);
}

// int	main()
// {
// 	void *str = "Test";
// 	int c = 2;
// 	size_t n = 3;
// 	ft_memset(str, c, n);
// 	return (1);
// }