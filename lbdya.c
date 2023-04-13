/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lbdya.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:07:47 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/13 00:34:10 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	what_to_push(t_elem *push_swap)
{
	t_list	*h;
	t_list	*head;
	t_list	*l;

	h = push_swap->longest;
	head = h->next;
	l = push_swap->a;
	while (1)
	{
		l->index = 1;
		l = l->next;
		if (l == push_swap->a)
			break ;
	}
	h->index = 0;
	while (1)
	{
		if (h->i < head->i)
			h = head;
		h->index = 0;
		head = head->next;
		if (head == push_swap->longest)
			break ;
	}
}

void	push_to_b(t_elem *push_swap)
{
	while (ft_lstsize(push_swap->a) > push_swap->l)
	{
		if (fake_swap(push_swap))
			continue ;
		else if (push_swap->a->index == 1)
			pb(push_swap, 1);
		else
			ra(push_swap, 1);
	}
}

void	from_b_to_a(t_elem *push_swap)
{
	t_list	*h;
	int		i;

	h = push_swap->b;
	push_swap->best_a = 0;
	push_swap->best_b = 0;
	i = ft_lstsize(push_swap->b);
	while (i)
	{
		re_indexing(push_swap->a);
		re_indexing(push_swap->b);
		best_move(push_swap);
		push_to_a(push_swap);
		pa(push_swap, 1);
		i--;
	}
}

void	longest(t_elem *push_swap)
{
	push_swap->l = 0;
	push_swap->h = push_swap->a;
	while (1)
	{
		push_swap->i = 1;
		push_swap->head = push_swap->h;
		push_swap->head0 = push_swap->head->next;
		norminette(push_swap);
		if (push_swap->i > push_swap->l)
		{
			push_swap->l = push_swap->i;
			push_swap->longest = push_swap->h;
		}
		push_swap->h->lon = push_swap->i;
		push_swap->h = push_swap->h->next;
		if (push_swap->h == push_swap->a)
			break ;
	}
	what_to_push(push_swap);
}

void	find_l(t_elem *push_swap)
{
	int	i;
	int	j;

	j = ft_lstsize(push_swap->a) / 2;
	longest(push_swap);
	push_to_b(push_swap);
	if (push_swap->b)
		from_b_to_a(push_swap);
	i = find_min(push_swap);
	if (i > j)
		i = i - ft_lstsize(push_swap->a);
	while (i > 0)
	{
		ra(push_swap, 1);
		i--;
	}
	while (i < 0)
	{
		rra(push_swap, 1);
		i++;
	}
}
