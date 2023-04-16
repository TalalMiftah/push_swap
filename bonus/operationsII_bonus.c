/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operationsII_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:21:01 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/14 20:23:29 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_elem *push_swap, int key)
{
	if (push_swap->a)
		push_swap->a = (push_swap->a)->next;
	if (key)
		ft_printf ("ra\n");
}

void	rb(t_elem *push_swap, int key)
{
	if (push_swap->b)
		push_swap->b = (push_swap->b)->next;
	if (key)
		ft_printf("rb\n");
}

void	rr(t_elem *push_swap, int key)
{
	ra(push_swap, 0);
	rb(push_swap, 0);
	if (key)
		ft_printf("rr\n");
}

void	rra(t_elem *push_swap, int key)
{
	if (push_swap->a)
		push_swap->a = (push_swap->a)->previous;
	if (key)
		ft_printf("rra\n");
}

void	rrb(t_elem *push_swap, int key)
{
	if (push_swap->b)
		push_swap->b = (push_swap->b)->previous;
	if (key)
		ft_printf("rrb\n");
}
