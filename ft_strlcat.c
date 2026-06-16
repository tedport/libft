/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:37:30 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/16 19:33:16 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_strnlen(char *str, unsigned int n)
{
	unsigned int	len;

	len = 0;
	while (str[len] != '\0' && len < n)
		len++;
	return (len);
}

static char	*ft_strncpy(char *dest, char *src, int n)
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

long unsigned int	ft_strlcat(char *dest, char *src, long unsigned int size)
{
	const unsigned int	srclen = ft_strlen(src);
	const unsigned int	dstlen = ft_strnlen(dest, size);

	if (dstlen >= size)
		return (size + srclen);
	if (srclen < size - dstlen)
		ft_strncpy(dest + dstlen, src, srclen + 1);
	else
	{
		ft_strncpy(dest + dstlen, src, size - dstlen - 1);
		dest[size - 1] = '\0';
	}
	return (dstlen + srclen);
}
