/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:34:21 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/16 22:27:03 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*ft_strjoin_get_next(char *s1, char *s2)
{
	char		*c1;
	ssize_t		i;
	ssize_t		r;

	i = -1;
	r = 0;
	if (!s1)
		s1 = ft_strdup("");
	if (!s2)
		s2 = ft_strdup("");
	c1 = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!c1)
		exit (1);
	while (s1[++i])
		c1[i] = s1[i];
	while (s2[r])
		c1[i++] = s2[r++];
	c1[i] = '\0';
	free(s1);
	return (c1);
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
	if (!c)
		exit (1);
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

char	*ft_read(int fd, char *str)
{
	int		bytes;
	char	*buff;

	bytes = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		exit (1);
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free (buff);
			free (str);
			return (NULL);
		}
		buff[bytes] = '\0';
		str = ft_strjoin_get_next(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_rhyme(char *s)
{
	ssize_t	i;
	char	*rhyme;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i])
	{
		if (s[i] == '\n')
		{
			i++;
			break ;
		}
		i++;
	}
	rhyme = malloc(i + 1);
	if (!rhyme)
		exit (1);
	rhyme[i--] = 0;
	while (i >= 0)
	{
		rhyme[i] = s[i];
		i--;
	}
	return (rhyme);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*c;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_read(fd, str);
	if (!str)
		return (NULL);
	c = ft_rhyme(str);
	str = next_ryhme(str);
	return (c);
}
