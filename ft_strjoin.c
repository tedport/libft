/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 00:52:27 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/26 13:49:17 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	const int	desired_len = ft_strlen(s1) + ft_strlen(s2);
	char		*out;

	out = malloc(desired_len + 1);
	if (!out)
		return (0);
	ft_strlcpy(out, s1, desired_len);
	ft_strlcat(out, s2, desired_len + 1);
	return (out);
}
