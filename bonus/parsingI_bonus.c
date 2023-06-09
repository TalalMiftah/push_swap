/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingI_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:34:37 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/16 21:21:40 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_elem *push_swap, int key)
{
	rra(push_swap, 0);
	rrb(push_swap, 0);
	if (key)
		ft_printf("rrr\n");
}

void	av_c(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[0] == '\0')
		ft_error();
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			j++;
		i++;
	}
	if (j == 0)
		ft_error();
}

char	*args_join(char	**av)
{
	int		i;
	char	*c;
	char	*buff;

	i = 1;
	c = ft_strdup("");
	while (av[i])
	{
		buff = c;
		av_c(av[i]);
		c = ft_strjoin(c, av[i]);
		if (buff)
			free (buff);
		i++;
	}
	return (c);
}

void	push(char **str, t_elem *push_swap)
{
	int		i;

	i = 0;
	push_swap->a = NULL;
	push_swap->b = NULL;
	while (str[i])
		ft_lstadd_back(&push_swap->a, lst_new(ft_atoi(str[i++])));
	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	main_parsing(t_elem *push_swap, char **av)
{
	char	**str;
	char	*c;

	c = args_join(av);
	str = ft_split(c, ' ');
	content_check(str);
	no_repeat(str);
	free(c);
	push(str, push_swap);
}
