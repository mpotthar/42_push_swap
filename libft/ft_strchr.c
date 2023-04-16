/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:20:57 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/11 07:49:20 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The strchr() function locates the first occurrence of c (converted to a
// char) in the string pointed to by s.  The terminating null character is
// considered to be part of the string; therefore if c is ‘\0’, the
// functions locate the terminating ‘\0’.
char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}
