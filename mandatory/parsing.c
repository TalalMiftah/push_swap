/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:19:49 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/09 20:03:24 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(char *c)
{
	ft_printf("Error\n%s\n", c);
	exit (1);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	ft_atoi(char *str)
{
	size_t	result;
	int		sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == 45 || *str == 43)
	{
		if (*str == 45)
			sign *= -1;
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		result *= 10;
		result += (*str - '0');
		if (result > 2147483648 && sign == -1)
			ft_error("An integer is less than INT_MIN");
		else if (result > 2147483647 && sign == 1)
			ft_error("An integer is bigger than INT_MAX");
		str++;
	}
	return (result * sign);
}

void	no_repeat(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 1;
		while (str[i + j])
		{
			if (ft_strcmp(str[i], str[i + j]) == 0)
				ft_error("their is an repeated number");
			j++;
		}
		i++;
	}
}

void	content_check(char **str)
{
	int	i;
	int	j;
	int	re;

	i = 0;
	while (str[i])
	{
		re = ft_atoi(str[i]);
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				ft_error("Check your arguments their is a character with them");
			j++;
		}
		i++;
	}
}
