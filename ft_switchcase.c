/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_switchcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/17 19:09:37 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/17 20:44:49 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c + ('A' - 'a') * (c >= 'a' && c <= 'z');
	return (uc);
}

int	ft_tolower(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c - ('A' - 'a') * (c >= 'A' && c <= 'Z');
	return (uc);
}
