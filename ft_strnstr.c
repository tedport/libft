/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 20:29:57 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/26 13:50:19 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	const size_t	little_len = ft_strlen(little);
	const char		*loc;

	loc = big - 1;
	while (1)
	{
		loc = ft_strchr(loc + 1, little[0]);
		if (loc - big + little_len > n || !loc)
			return (0);
		if (!ft_strncmp(loc, little, little_len))
			return ((char *)loc);
	}
}
