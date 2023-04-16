/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsndlast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 13:18:15 by mpotthar          #+#    #+#             */
/*   Updated: 2023/04/16 13:18:19 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Returns the second last node of the list
t_list	*ft_lstsndlast(t_list *lst)
{
	int	len;

	len = ft_lstsize(lst);
	while (len > 2)
	{
		lst = lst->next;
		len--;
	}
	return (lst);
}
