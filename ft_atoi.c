/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 19:35:27 by vtarasov          #+#    #+#             */
/*   Updated: 2026/07/03 17:11:05 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

int	ft_atoi(const char *nptr)
{
	int			sign;
	long long	ret;

	while (ft_isspace(*nptr))
		nptr++;
	ret = 0;
	sign = 1;
	if (nptr[0] == '-')
	{
		sign = -1;
		nptr++;
	}
	else if (nptr[0] == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		ret *= 10;
		ret += *nptr - '0';
		nptr++;
	}
	return ((int)((long long)sign * ret));
}
