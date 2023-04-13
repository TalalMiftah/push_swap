/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmiftah <tmiftah@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 20:33:15 by tmiftah           #+#    #+#             */
/*   Updated: 2023/04/13 00:33:39 by tmiftah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdio.h>

typedef struct s_list
{
	int				i;
	int				index;
	int				lon;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef struct elements
{
	t_list	*a;
	t_list	*b;
	t_list	*longest;
	t_list	*head;
	t_list	*head0;
	t_list	*h;
	t_list	*new_head;
	int		l;
	int		i;
	int		j;
	int		plongest;
	int		best_a;
	int		best_b;
	int		best_a0;
	int		best_b0;
}	t_elem;

void	content_check(char **str);
void	ft_lstclear(t_elem *push_swap);
void	no_repeat(char **str);
int		ft_printf(const char *s, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putstr(const char *s);
char	*ft_strjoin(char *str1, char *str2);
int		ft_strlen(char *str);
char	*ft_strdup(char *s);
char	**ft_split(char const *s, char c);
int		ft_strcmp(char *s1, char *s2);
void	ft_error(char *c);
int		ft_atoi(char *str);
void	push(char **str, t_elem *push_swap);
void	av_c(char *str);
void	longest(t_elem *push_swap);
void	norminette(t_elem *push_swap);

void	ft_lstadd_back(t_list **l, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*lst_new(int n);
void	find_l(t_elem *push_swap);
void	re_indexing(t_list *h);
int		ft_max(int a, int b);
int		find_position(t_list *b, t_elem *push_swap);
int		absolute_value(int i);
void	best_move(t_elem *push_swap);
void	from_b_to_a(t_elem *push_swap);
int		fake_swap(t_elem *push_swap);
void	push_to_a(t_elem *push_swap);
int		find_min(t_elem *push_swap);
void	what_to_push(t_elem *push_swap);

void	sa(t_elem *push_swap, int key);
void	sb(t_elem *push_swap, int key);
void	ss(t_elem *push_swap, int key);
void	pa(t_elem *push_swap, int key);
void	pb(t_elem *push_swap, int key);
void	ra(t_elem *push_swap, int key);
void	rb(t_elem *push_swap, int key);
void	rr(t_elem *push_swap, int key);
void	rra(t_elem *push_swap, int key);
void	rrb(t_elem *push_swap, int key);
void	rrr(t_elem *push_swap, int key);
void	main_parsing(t_elem *push_swap, char **av);

#endif