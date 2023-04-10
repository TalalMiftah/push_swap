/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 22:36:55 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/09 20:20:29 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	re_indexing(t_list *h)
{
	t_list	*head;
	int		i;

	i = 0;
	head = h;
	while (1)
	{
		head->index = i;
		head = head->next;
		i++;
		if (head == h)
			break ;
	}
}

void	noeminette2(t_elem *push_swap)
{
	while (push_swap->best_a0 < 0 && push_swap->best_b0 < 0)
	{
		rrr(push_swap, 1);
		push_swap->best_a0++;
		push_swap->best_b0++;
	}
	while (push_swap->best_a0 < 0)
	{
		rra(push_swap, 1);
		push_swap->best_a0++;
	}
	while (push_swap->best_b0 < 0)
	{
		rrb(push_swap, 1);
		push_swap->best_b0++;
	}
}

void	push_to_a(t_elem *push_swap)
{
	noeminette2(push_swap);
	while (push_swap->best_a0 > 0 && push_swap->best_b0 > 0)
	{
		rr(push_swap, 1);
		push_swap->best_a0--;
		push_swap->best_b0--;
	}
	while (push_swap->best_a0 > 0)
	{
		ra(push_swap, 1);
		push_swap->best_a0--;
	}
	while (push_swap->best_b0 > 0)
	{
		rb(push_swap, 1);
		push_swap->best_b0--;
	}
}

void	norminette1(t_elem *push_swap, t_list *h)
{
	if (find_position(h, push_swap) > ft_lstsize(push_swap->a) / 2)
		push_swap->best_a = find_position(h, push_swap)
			- ft_lstsize(push_swap->a);
	else
		push_swap->best_a = find_position(h, push_swap);
	if (h->index > ft_lstsize(push_swap->b) / 2)
		push_swap->best_b = h->index - ft_lstsize(push_swap->b);
	else
		push_swap->best_b = h->index;
	if ((push_swap->best_a >= 0 && push_swap->best_b >= 0)
		|| (push_swap->best_a < 0 && push_swap->best_b < 0))
		push_swap->i = ft_max(absolute_value(push_swap->best_a),
				absolute_value(push_swap->best_b));
	else
		push_swap->i = absolute_value(push_swap->best_a)
			+ absolute_value(push_swap->best_b);
}

void	best_move(t_elem *push_swap)
{
	t_list	*h;
	int		tmp;

	push_swap->i = 0;
	tmp = 2147483647;
	h = push_swap->b;
	while (1)
	{
		norminette1(push_swap, h);
		if (push_swap->i <= tmp)
		{
			push_swap->best_a0 = push_swap->best_a;
			push_swap->best_b0 = push_swap->best_b;
			tmp = push_swap->i;
		}
		h = h->next;
		if (h == push_swap->b)
			break ;
	}
}
