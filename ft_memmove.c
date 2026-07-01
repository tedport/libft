/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:36:55 by vtarasov          #+#    #+#             */
/*   Updated: 2026/07/01 18:58:34 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*uc_src;
	unsigned char		*uc_dst;

	uc_src = src;
	uc_dst = dest;
	if (uc_src < uc_dst)
	{
		while (n-- > 0)
			uc_dst[n] = uc_src[n];
	}
	else
		ft_memcpy(uc_dst, uc_src, n);
	return (dest);
}
