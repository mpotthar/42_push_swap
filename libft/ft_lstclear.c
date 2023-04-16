/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:29:19 by mpotthar          #+#    #+#             */
/*   Updated: 2023/04/16 13:20:07 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Deletes and frees the given node and every
// successor of that node, using the function ’del’
// and free(3).
// Finally, the pointer to the list must be set to
// NULL.
void	ft_lstclear(t_list **lst)
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = *lst;
		*lst = tmp->next;
		free(tmp);
	}
	*lst = NULL;
}
