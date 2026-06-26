/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 13:09:55 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/25 00:20:48 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	size_t	slen;
	size_t	cntr;
	char	*nstr;

	cntr = 0;
	slen = ft_strlen(s);
	nstr = malloc(slen + 1);
	if (!nstr)
		return (0);
	while (cntr < slen + 1)
	{
		nstr[cntr] = s[cntr];
		cntr++;
	}
	return (nstr);
}
