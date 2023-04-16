/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 12:25:37 by mpotthar          #+#    #+#             */
/*   Updated: 2023/04/16 13:20:12 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Adds the node ’new’ at the end of the list.
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!(*lst))
		*lst = new;
	else
		ft_lstlast(*lst)->next = new;
}
