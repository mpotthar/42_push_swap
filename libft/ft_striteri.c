/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 07:04:45 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/11 07:49:28 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Applies the function ’f’ on each character of the string passed 
// as argument, passing its index as first argument. Each character 
// is passed by address to ’f’ to be modified if necessary.
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = -1;
	while (s[++i])
		f(i, s + i);
}
