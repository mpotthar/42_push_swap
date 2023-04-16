/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:23:17 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/11 07:49:16 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	ft_count_strings(const char *s, char c)
{
	int	i;
	int	counter;

	i = -1;
	counter = 0;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] != c && s[i] != '\0')
				i++;
			if (s[i] == '\0')
				break ;
		}
	}
	return (counter);
}

static char	**ft_split_string(char **result, const char *s, char c, int j)
{
	int	i;
	int	start;

	i = -1;
	while (s[++i] != '\0')
	{
		if (s[i] != c)
		{
			start = i;
			while (s[i] != c && s[i] != '\0')
				i++;
			result[j] = ft_substr(s, start, i - start);
			if (result[j++] == NULL)
			{
				while (--j >= 0)
					free(result[j]);
				free(result);
				return (NULL);
			}
			if (s[i] == '\0')
				break ;
		}
	}
	result[j] = NULL;
	return (result);
}

// Allocates (with malloc(3)) and returns an array of strings obtained by 
// splitting ’s’ using the character ’c’ as a delimiter. The array must 
// end with a NULL pointer.
char	**ft_split(const char *s, char c)
{
	char	**result;

	result = (char **)malloc ((ft_count_strings(s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	if (ft_split_string(result, s, c, 0) == NULL)
		return (NULL);
	return (result);
}

// int main(void)
// {
//     // const char *s = "64356456456";
//     // char c = 0;
//     int i = -1;
//     char **result;

//     result = ft_split("^^^1^^2a,^^^^3^^^^--h^^^^", '^');
//     while (result[++i] != NULL)
// 	{
//     	printf("String:%s\n", result[i]);
// 		free(result[i]);
// 	}
//     free(result);

//     // const char *s = "#######";
//     // char c = '#';

//     // printf("Counter: %d\n", ft_count_strings(s, c));
// }