/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:03:57 by vtarasov          #+#    #+#             */
/*   Updated: 2026/07/01 19:01:13 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	integer_as_string_length(long long n)
{
	size_t		len;
	long long	t;

	len = 0;
	t = n;
	if (t == 0)
		return (1);
	if (t < 0)
	{
		len++;
		t = -t;
	}
	while (t)
	{
		t /= 10;
		len++;
	}
	return (len);
}

static char	*internal_itoa(long long n, char *dst)
{
	const char	*odst = dst;

	if (n < 0)
	{
		*dst = '-';
		n = -n;
	}
	dst += integer_as_string_length(n);
	*(dst--) = 0;
	while (1)
	{
		*(dst--) = (n % 10) + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	return ((char *)odst);
}

char	*ft_itoa(int n)
{
	long long	t;
	char		*result;

	t = n;
	if (!t)
		return (ft_strdup("0"));
	result = ft_calloc(integer_as_string_length(t) + 1, 1);
	if (!result)
		return (0);
	internal_itoa(t, result);
	return (result);
}
