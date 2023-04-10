/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 22:37:08 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/09 22:09:32 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	fake_swap(t_elem *push_swap)
{
	push_swap->plongest = push_swap->l;
	sa(push_swap, 0);
	longest(push_swap);
	if (push_swap->l > push_swap->plongest)
		ft_printf("sa\n");
	else
	{
		sa(push_swap, 0);
		longest(push_swap);
	}
}

void	to_b(int i, t_elem *push_swap)
{
	int	j;

	j = ft_lstsize(push_swap->a) - i + 1;
	if (i <= ft_lstsize(push_swap->a) / 2)
	{
		while (i != 1)
		{
			ra(push_swap, 1);
			i--;
		}
		pb(push_swap, 1);
	}
	if (i > ft_lstsize(push_swap->a) / 2)
	{
		while (j != 0)
		{
			rra(push_swap, 1);
			j--;
		}
		pb(push_swap, 1);
	}
}

// void	norminette(t_elem *push_swap)
// {
// 	while (1)
// 	{
// 		if (push_swap->head->i < push_swap->head0->i)
// 		{
// 			push_swap->i++;
// 			push_swap->head = push_swap->head0;
// 		}
// 		push_swap->head0 = push_swap->head0->next;
// 		if (push_swap->head0 == push_swap->head)
// 			break ;
// 	}
// }

int	find_min(t_elem *push_swap)
{
	int		tmp;
	int		i;
	t_list	*h;

	h = push_swap->a;
	tmp = 2147483647;
	i = 0;
	re_indexing(push_swap->a);
	while (1)
	{
		if (h->i < tmp)
		{
			tmp = h->i;
			push_swap->new_head = h;
			i = h->index;
		}
		h = h->next;
		if (h == push_swap->a)
			break ;
	}
	return (i);
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
