/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekeen-wy <ekeen-wy@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:59:04 by ekeen-wy          #+#    #+#             */
/*   Updated: 2021/12/09 16:39:24 by ekeen-wy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tempnode;

	while (*lst != NULL)
	{
		tempnode = *lst;
		if ((*del) != NULL)
			(*del)(tempnode -> content);
		*lst = tempnode -> next;
		free(tempnode);
	}
	*lst = NULL;
}
