/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:16:28 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/12 02:51:16 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_elem	push_swap;

	push_swap.l = 1;
	if (ac < 2)
		exit(1);
	main_parsing(&push_swap, av);
	find_l(&push_swap);
	t_list *h = push_swap.a;
	do
	{
		printf("%d\n", h->i);
		h = h->next;
	} while (h != push_swap.a);
	printf("================\n");
	printf("%d\n", push_swap.l);
}
