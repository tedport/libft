/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:03:57 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/26 17:38:05 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	integer_as_string_length(int n)
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

static char	*internal_reverse_string(char *str)
{
	int	istrlen;
	int	cnt;
	int	tmp;

	istrlen = 0;
	while (str[istrlen])
		istrlen++;
	cnt = 0;
	while (cnt < istrlen - cnt)
	{
		tmp = str[cnt];
		str[cnt] = str[istrlen - cnt - 1];
		str[istrlen - cnt - 1] = tmp;
		cnt++;
	}
	return (str);
}

static char	*internal_itoa(long long int n, char *dst)
{
	const char	*odst = dst;
	int			sign;
	char		c;

	sign = 0;
	if (n < 0)
	{
		*dst = '-';
		dst++;
		n = -n;
		sign = 1;
	}
	while (1)
	{
		*dst = (n % 10) + '0';
		dst++;
		n /= 10;
		if (n == 0)
			break ;
	}
	*dst = 0;
	internal_reverse_string((char *)(odst + sign));
	return ((char *)odst);
}

char	*ft_itoa(int n)
{
	long long	t;
	char		*result;

	t = n;
	if (!t)
		return (ft_strdup("0"));
	result = ft_calloc(integer_as_string_length(n) + 1, 1);
	if (!result)
		return (0);
	internal_itoa(t, result);
	return (result);
}
