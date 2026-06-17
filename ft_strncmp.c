/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 20:32:22 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/17 20:57:19 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	n--;
	while (*s1 != '\0' && *s1 == *s2 && n > 0)
	{
		s1++;
		s2++;
		n--;
	}
	return (*s1 - *s2);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*uc_s1 = s1;
	const unsigned char	*uc_s2 = s2;

	if (!n)
		return (0);
	n--;
	while (*uc_s1 != '\0' && *uc_s1 == *uc_s2 && n > 0)
	{
		uc_s1++;
		uc_s2++;
		n--;
	}
	return (*uc_s1 - *uc_s2);
}
