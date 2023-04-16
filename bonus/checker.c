/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:36:38 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/16 22:12:23 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	catch_instruction(t_elem *push_swap, char *str)
{
	if (str && ft_strcmp(str, "sa\n") == 0)
		sa(push_swap, 0);
	else if (str && ft_strcmp(str, "sb\n") == 0)
		sb(push_swap, 0);
	else if (str && ft_strcmp(str, "ss\n") == 0)
		ss(push_swap, 0);
	else if (str && ft_strcmp(str, "pa\n") == 0)
		pa(push_swap, 0);
	else if (str && ft_strcmp(str, "pb\n") == 0)
		pb(push_swap, 0);
	else if (str && ft_strcmp(str, "ra\n") == 0)
		ra(push_swap, 0);
	else if (str && ft_strcmp(str, "rb\n") == 0)
		rb(push_swap, 0);
	else if (str && ft_strcmp(str, "rr\n") == 0)
		rr(push_swap, 0);
	else if (str && ft_strcmp(str, "rra\n") == 0)
		rra(push_swap, 0);
	else if (str && ft_strcmp(str, "rrb\n") == 0)
		rrb(push_swap, 0);
	else if (str && ft_strcmp(str, "rrr\n") == 0)
		rrr(push_swap, 0);
	else
		return (write(2, "Error\n", 6), exit(1));
}

int	is_sorted(t_elem *push_swap)
{
	t_list	*head;
	t_list	*h;

	head = push_swap->a;
	while (head)
	{
		h = head->next;
		if (head->i > h->i)
			return (0);
		head = head->next;
		if (head->next == push_swap->a)
			break ;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_elem	push_swap;
	char	*str;

	if (ac < 2)
		exit(1);
	main_parsing(&push_swap, av);
	str = get_next_line(0);
	while (str)
	{
		catch_instruction(&push_swap, str);
		free(str);
		str = get_next_line(0);
	}
	if (is_sorted(&push_swap) && ft_lstsize(push_swap.b) == 0)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	ft_lstclear(&push_swap);
	return (0);
}
