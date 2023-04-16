/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 21:17:12 by mpotthar          #+#    #+#             */
/*   Updated: 2023/01/11 07:50:10 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The ft_tolower() function converts an upper-case letter to the corresponding
// lower-case letter.
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = c - ('A' - 'a');
	return (c);
}
