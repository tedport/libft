/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarasov <vtarasov@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 12:27:48 by vtarasov          #+#    #+#             */
/*   Updated: 2026/06/26 13:48:42 by vtarasov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	word_len(char const *s, char delimiter)
{
	int	i;

	i = 0;
	while (s[i] != delimiter)
		i++;
	return (i);
}

static const char	*next_word(char const *s, char delimiter)
{
	int	b_delimiterwasfound;

	b_delimiterwasfound = 0;
	while (*s)
	{
		if (*s == delimiter)
			b_delimiterwasfound = 1;
		if (*s != delimiter && b_delimiterwasfound)
			return (s);
		s++;
	}
	return (0);
}

static size_t	wc(char const *s, char delimiter)
{
	size_t		words;
	const char	*current_word;

	words = 0;
	if (*s && *s != delimiter)
		words++;
	current_word = s;
	while (1)
	{
		current_word = next_word(current_word, delimiter);
		if (current_word)
			words++;
		else
			return (words);
	}
}

char	**ft_split(char const *s, char c)
{
	int			word_index;
	char		**lines;
	const char	*current_word;

	lines = malloc((wc(s, c) + 1) * sizeof(char *));
	lines[wc(s, c)] = 0;
	current_word = s;
	word_index = 0;
	while (current_word)
	{
		if (*current_word != c)
			lines[word_index] = ft_substr(current_word, 0,
					word_len(current_word, c));
		current_word = next_word(current_word, c);
		word_index++;
	}
	return (lines);
}
