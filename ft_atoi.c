/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 19:35:27 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/16 19:47:24 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	ret;

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
	return (sign * ret);
}
