/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 20:59:20 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/24 13:08:17 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memory;

	if (nmemb > __SIZE_MAX__ / size)
		return (0);
	memory = malloc(nmemb * size);
	if (!memory || size * nmemb == 0)
		return (memory);
	ft_bzero(memory, size * nmemb);
	return (memory);
}
