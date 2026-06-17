/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 20:29:57 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/17 20:44:44 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	const int	to_find_len = ft_strlen(little);

	if (!to_find_len)
		return ((char *)big);
	while (*big && n)
	{
		if (!ft_strncmp(big, little, to_find_len))
			return ((char *)big);
		big++;
		n--;
	}
	return (0);
}
