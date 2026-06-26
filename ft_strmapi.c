/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 13:29:10 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/26 13:37:37 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		idx;

	new = ft_strdup(s);
	if (!new)
		return (0);
	idx = 0;
	while (new[idx])
	{
		new[idx] = f(idx, s[idx]);
		idx++;
	}
	return (new);
}
