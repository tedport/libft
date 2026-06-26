/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:36:55 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/24 20:24:51 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// [=====]
//   [=====]

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (dest - src >= (long signed int)n)
	{
		ft_memcpy(dest, src, n);
	}
	else
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((const char *)src)[n - 1];
			n--;
		}
	}
	return (dest);
}
