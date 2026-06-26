/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switchcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 19:09:37 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/26 15:10:14 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (!(c >= 'a' && c <= 'z'))
		return (uc);
	uc += ('A' - 'a');
	return (uc);
}

int	ft_tolower(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (!(c >= 'A' && c <= 'Z'))
		return (uc);
	uc -= ('A' - 'a');
	return (uc);
}
