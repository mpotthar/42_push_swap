/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 08:35:17 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/11 07:49:54 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// The ft_strnstr() function locates the first occurrence of the null-
// terminated string needle in the string haystack, where not more than len
// characters are searched.  Characters that appear after a ‘\0’ character
// are not searched.
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	needle_len;
	size_t	haystack_len;

	needle_len = ft_strlen(needle);
	haystack_len = ft_strlen(haystack);
	if (needle == NULL)
		return ((char *)haystack);
	while (len >= needle_len && haystack_len >= needle_len)
	{
		len--;
		haystack_len--;
		if (!ft_memcmp(haystack, needle, needle_len))
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>

// int main(void)
// {
//     char* s1 = "42WobWolfsburg";
//     char* s2 = "Wolf";
//     size_t len;

//     len = ft_strlen(s1);
//     printf("Original: %s\n", strnstr(s1, s2, len));
//     printf("Reproduction: %s\n", ft_strnstr(s1, s2, len));
//     printf("\nOriginal: %s\n", strnstr(s1, s1, len));
//     printf("Reproduction: %s\n", ft_strnstr(s1, s1, len));
// }