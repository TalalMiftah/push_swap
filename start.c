/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:13:24 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/12 23:37:23 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*lst_new(int n)
{
	t_list	*h;

	h = malloc(sizeof(t_list));
	h->i = n;
	h->next = h;
	h->previous = h;
	h->index = 1;
	h->lon = 1;
	return (h);
}

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*h;

	h = lst;
	while (1)
	{
		if (h->next == lst)
			break ;
		h = h->next;
	}
	return (h);
}

void	ft_lstadd_back(t_list **l, t_list *new)
{
	t_list	*swap;
	t_list	*h;

	h = *l;
	if (!l || !new)
		exit (1);
	if (!*l)
	{
		*l = new;
		return ;
	}
	swap = ft_lstlast(h);
	swap->next = new;
	new->previous = swap;
	new->next = h;
	h->previous = new;
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst)
		return ;
	if (*lst)
	{
		new->next = *lst;
		new->previous = (*lst)->previous;
		(*lst)->previous = new;
		ft_lstlast(*lst)->next = new;
	}
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*h;

	h = lst;
	count = 0;
	while (1)
	{
		count++;
		lst = lst -> next;
		if (lst == h)
			break ;
	}
	return (count);
}
