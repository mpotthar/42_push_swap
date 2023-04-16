/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 09:29:28 by mpotthar          #+#    #+#             */
/*   Updated: 2023/04/16 13:26:28 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//creates new list with content as content and
//null as next adress. returns the new node.
t_list	*ft_lstnew(int num)
{
	t_list	*new;

	new = (t_list *) malloc (sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}
