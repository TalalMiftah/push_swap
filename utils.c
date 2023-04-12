/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:37:08 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/12 23:37:31 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	fake_swap(t_elem *push_swap)
{
	int	tmp;

	tmp = push_swap->l;
	sa(push_swap, 0);
	longest(push_swap);
	if (push_swap->l > tmp)
	{
		ft_printf("sa\n");
		return (1);
	}
	else
	{
		sa(push_swap, 0);
		longest(push_swap);
	}
	return (0);
}

void	norminette(t_elem *push_swap)
{
	while (1)
	{
		if (push_swap->head->i < push_swap->head0->i)
		{
			push_swap->i++;
			push_swap->head = push_swap->head0;
		}
		push_swap->head0 = push_swap->head0->next;
		if (push_swap->head0 == push_swap->head)
			break ;
	}
}

int	find_min(t_elem *push_swap)
{
	int		tmp;
	int		i;
	int		j;
	t_list	*h;

	h = push_swap->a;
	tmp = 2147483647;
	i = 0;
	j = 0;
	while (1)
	{
		re_indexing(push_swap->a);
		if (h->i < tmp)
		{
			tmp = h->i;
			push_swap->new_head = h;
			j = i;
		}
		i++;
		h = h->next;
		if (h == push_swap->a)
			break ;
	}
	return (j);
}

int	find_position(t_list *b, t_elem *push_swap)
{
	t_list	*head;

	head = push_swap->a;
	while (1)
	{
		if (head->i > b->i && head->next->i > b->i)
		{
			if (head->i > head->next->i)
				return (head->next->index);
		}
		if (head->i < b->i && head->next->i > b->i)
			return (head->next->index);
		head = head->next;
		if (head == push_swap->a)
			break ;
	}
	return (head->index);
}
