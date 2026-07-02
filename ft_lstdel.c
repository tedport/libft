/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:27:34 by vtarasov          #+#    #+#             */
/*   Updated: 2026/07/02 14:38:04 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*cur;
	t_list	*prev;

	if (!(*lst))
		return ;
	cur = (*lst)->next;
	prev = (*lst);
	while (cur != 0)
	{
		ft_lstdelone(prev, del);
		prev = cur;
		cur = cur->next;
	}
	if (prev)
		ft_lstdelone(prev, del);
	if (cur)
		ft_lstdelone(cur, del);
	*lst = 0;
}
