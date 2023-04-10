/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 18:58:15 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/09 20:04:33 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	char	*s1;

	i = ft_strlen(s) + 1;
	s1 = malloc(i);
	if (!s1)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s1[i] = s[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

int	absolute_value(int i)
{
	if (i < 0)
		return (-i);
	else
		return (i);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int		i;
	int		j;
	char	*c;

	i = 0;
	j = 0;
	if (!str1 || !str2)
		exit (1);
	c = malloc(ft_strlen(str1) + ft_strlen(str2) + 2);
	while (str1[i])
	{
		c[i] = str1[i];
		i++;
	}
	while (str2[j])
		c[i++] = str2[j++];
	c[i] = ' ';
	c[++i] = 0;
	return (c);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
