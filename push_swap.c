/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:16:28 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/13 00:38:39 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ls(void)
{
	system("leaks push_swap");
}

int	main(int ac, char **av)
{
	t_elem	push_swap;

	push_swap.l = 1;
	if (ac < 2)
		exit(1);
	atexit(ls);
	main_parsing(&push_swap, av);
	find_l(&push_swap);
	ft_lstclear(&push_swap);
}
