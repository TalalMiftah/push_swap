/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 11:43:22 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/14 20:39:45 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_elem *push_swap, int key)
{
	int	swap;

	if ((push_swap->a) && ((push_swap->a)->next != push_swap->a))
	{
		swap = (push_swap->a)->i;
		(push_swap->a)->i = (push_swap->a)->next->i;
		(push_swap->a)->next->i = swap;
		if (key)
			ft_printf("sa\n");
	}
}

void	sb(t_elem *push_swap, int key)
{
	int	swap;

	if (push_swap->b && (push_swap->b)->next != push_swap->b)
	{
		swap = (push_swap->b)->i;
		(push_swap->b)->i = (push_swap->b)->next->i;
		(push_swap->b)->next->i = swap;
		if (key)
			ft_printf("sb\n");
	}
}

void	ss(t_elem *push_swap, int key)
{
	sb(push_swap, key);
	sa(push_swap, key);
	if (key)
		ft_printf("ss\n");
}

void	pa(t_elem *push_swap, int key)
{
	t_list	*swap;
	t_list	*s;

	swap = push_swap->b;
	if (push_swap->b)
	{
		s = ft_lstlast(push_swap->b);
		ft_lstadd_front(&push_swap->a, lst_new((push_swap->b)->i));
		push_swap->a->lon = push_swap->b->lon;
		push_swap->b = swap->next;
		push_swap->b->previous = s;
		s->next = push_swap->b;
		free (swap);
		if (key)
			ft_printf("pa\n");
	}
}

void	pb(t_elem *push_swap, int key)
{
	t_list	*swap;
	t_list	*s;

	swap = push_swap->a;
	if (push_swap->a)
	{
		s = ft_lstlast(push_swap->a);
		ft_lstadd_front(&push_swap->b, lst_new((push_swap->a)->i));
		push_swap->b->lon = push_swap->a->lon;
		push_swap->a = swap->next;
		push_swap->a->previous = s;
		s->next = push_swap->a;
		free (swap);
		if (key)
			ft_printf("pb\n");
	}
}
