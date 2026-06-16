/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:36:55 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/16 17:30:32 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, long unsigned int n)
{
	int	a;

	a = 0;
	while (a < n)
	{
		((char *)dest)[a] = ((const char *)src)[a];
		a++;
	}
	return (dest);
}
