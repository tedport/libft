/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 18:50:52 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/26 15:42:07 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	const size_t	srcsize = ft_strlen(src);
	size_t			counter;

	counter = 0;
	if (size == 0)
		return (srcsize);
	while (counter < size - 1 && counter < srcsize)
	{
		dest[counter] = src[counter];
		counter++;
	}
	dest[counter] = 0;
	return (srcsize);
}
