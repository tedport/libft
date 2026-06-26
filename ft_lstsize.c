/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:23:36 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/26 20:07:32 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cntr;

	cntr = 1;
	if (!lst)
		return (0);
	while (lst->next)
	{
		lst = lst->next;
		cntr++;
	}
	return (cntr);
}
