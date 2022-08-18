/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 21:48:04 by ekeen-wy          #+#    #+#             */
/*   Updated: 2021/11/25 12:03:03 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*header;
	t_list	*node;

	header = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew((*f)(lst -> content));
		if (node == NULL)
			ft_lstclear(&header, *del);
		ft_lstadd_back(&header, node);
		lst = lst -> next;
	}
	return (header);
}
