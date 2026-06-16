/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/16 14:16:19 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/16 19:40:19 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_strlen(const char *str);
void				*ft_memcpy(void *dest, const void *src,
						long unsigned int n);
void				ft_bzero(void *s, long unsigned int n);
void				*ft_memset(void *s, int c, long unsigned int n);
void				*ft_memmove(void *dest, const void *src,
						long unsigned int n);
long unsigned int	ft_strlcpy(char *dest, const char *src,
						long unsigned int size);
long unsigned int	ft_strlcat(char *dest, const char *src,
						long unsigned int size);
// ft_toupper
// ft_tolower
// ft_strchr
// ft_strrchr
// ft_strncmp
// ft_memchr
// ft_memcmp
// ft_strnstr
int ft_atoi(const char *nptr);
// ft_calloc
// ft_strdup

#endif