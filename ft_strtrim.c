/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 11:28:20 by dtarasov          #+#    #+#             */
/*   Updated: 2026/06/29 19:50:33 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static long long	first_nonset_idx(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (!is_in_set(s1[i], set))
			return ((long long)i);
		i++;
	}
	return (-1);
}

static long long	first_nonset_idx_bwd(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1);
	while (1)
	{
		if (!is_in_set(s1[i], set))
			return ((long long)i);
		if (i == 0)
			break ;
		i--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	long long	start;
	long long	end;

	start = first_nonset_idx(s1, set);
	if (start < 0)
		return (ft_strdup(""));
	end = first_nonset_idx_bwd(s1, set);
	return (ft_substr(s1, start, end - start));
}
