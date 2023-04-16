/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:53:56 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/11 07:48:05 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_isascii() function tests for an ASCII character, which is any
// character between 0 and 127 inclusive.
int	ft_isascii(int c)
{
	if ((c >= 0 && c <= 127))
		return (1);
	return (0);
}
