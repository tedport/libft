/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 19:09:22 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/24 21:12:14 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (1)
	{
		if (*s == c)
			return ((char *)s);
		if (*s == 0)
			break ;
		s++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	const char *const	os = s;

	while (*s)
		s++;
	while (1)
	{
		if (*s == c)
			return ((char *)s);
		if (s == os)
			break ;
		s--;
	}
	return (0);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*int8s = (const unsigned char *)s;
	const unsigned char	uc = c;

	while (1)
	{
		if (*int8s == uc)
			return ((void *)int8s);
		if (!n)
			break ;
		int8s++;
		n--;
	}
	return (0);
}
