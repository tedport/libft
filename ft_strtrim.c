/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 01:14:28 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/26 12:26:24 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*(set++) == c)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	const char *const	original_source = s1;
	int					b_trimming;
	size_t				substr_start;
	size_t				substr_end;

	b_trimming = 1;
	substr_start = 0;
	while (*s1)
	{
		if (!is_in_set(*s1, set))
			b_trimming = 0;
		if (b_trimming)
			substr_start++;
		s1++;
	}
	substr_end = substr_start;
	while (s1 != original_source + substr_start && is_in_set(*s1, set))
	{
		substr_end++;
		s1--;
	}
	return (ft_substr(s1, substr_start, substr_end - substr_start));
}
