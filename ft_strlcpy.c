/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:50:52 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/16 19:32:56 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strncpy(char *dest, const char *src, unsigned int n)
{
	int	i;

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

long unsigned int	ft_strlcpy(char *dest, const char *src,
		long unsigned int size)
{
	const unsigned int	srclen = ft_strlen(src);

	if (size == 0)
		return (srclen);
	if (size < srclen)
		ft_strncpy(dest, src, size - 1);
	else
		ft_strncpy(dest, src, srclen + 1);
	dest[size - 1] = 0;
	return (srclen);
}
