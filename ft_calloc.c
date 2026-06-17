/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 20:59:20 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/17 22:23:41 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

// n > 2^32/s

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	memory = malloc(nmemb * size);
	if (!memory || size * nmemb == 0)
		return (memory);
	ft_bzero(memory, size * nmemb);
	return (memory);
}
