/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 00:29:46 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/26 16:04:52 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	real_len;

	real_len = ft_strlen(s + start);
	if (real_len > len)
		real_len = len;
	if (start > ft_strlen(s))
		real_len = 0;
	sub = malloc(real_len + 1);
	if (!sub)
		return (0);
	ft_strlcpy(sub, s + start, real_len + 1);
	return (sub);
}
