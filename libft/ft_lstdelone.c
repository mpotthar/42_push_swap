/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpotthar <mpotthar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:15:51 by mpotthar          #+#    #+#             */
/*   Updated: 2023/04/16 13:25:41 by mpotthar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//Takes as a parameter a node and frees the memory of
//the node’s content using the function ’del’ given
//as a parameter and free the node. The memory of
//’next’ must not be freed.
void	ft_lstdelone(t_list *lst)
{
	free(lst);
}
