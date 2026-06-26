/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:50:52 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/24 20:24:26 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dest, const char *src,
		size_t size)
{
	const size_t	srclen = ft_strlen(src);

	if (size == 0)
		return (srclen);
	if (size <= srclen)
		ft_strncpy(dest, src, size - 1);
	else
		ft_strncpy(dest, src, srclen + 1);
	dest[size - 1] = 0;
	return (srclen);
}
