/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:58:26 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/16 22:27:23 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	word_count(const char *s, char c)
{
	int	j;

	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
			j++;
		while (*s && *s != c)
			s++;
	}
	return (j);
}

static int	size(const char *s, char c)
{
	int	j;

	j = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		j++;
		s++;
	}
	return (j);
}

static char	*allocation_of_words(const char *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(size(s, c) * sizeof(char) + 1);
	if (!word)
		exit (1);
	while (*s && *s != c)
		word[i++] = *s++;
	word[i] = '\0';
	return (word);
}

static void	frees(char **ptr, int j)
{
	while (j > 0)
	{
		free(ptr[j - 1]);
		j--;
	}
	free(ptr);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	int		i;
	char	**ptr;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	ptr = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!ptr)
		exit (1);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			ptr[j++] = allocation_of_words(&s[i++], c);
		if (j > 0 && !ptr[j - 1])
			return (frees(ptr, j), NULL);
		while (s[i] && s[i] != c)
			i++;
	}
	ptr[j] = NULL;
	return (ptr);
}
