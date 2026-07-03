/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 19:02:08 by vtarasov          #+#    #+#             */
/*   Updated: 2026/07/03 17:08:26 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*current;
	t_list	*new;

	if (!lst)
		return (0);
	start = ft_lstnew(f(lst->content));
	if (!start)
		return (0);
	current = lst;
	while (current->next)
	{
		current = current->next;
		new = ft_lstnew(f(current->content));
		if (!new)
		{
			ft_lstclear(&start, del);
			return (0);
		}
		ft_lstadd_back(&start, new);
	}
	return (start);
}
