/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:35:15 by abayar            #+#    #+#             */
/*   Updated: 2022/02/28 20:27:43 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				i;
	int				index;
	struct s_list	*next;
}	t_list;

typedef struct node
{
	int		j;
	int		y;
	char	*s;
}	node;

void	ft_lstadd_back(t_list **alst, int data);
void	ft_lstadd_front(t_list **alst, int data, int index);
t_list	*ft_lstlast(t_list **head, t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list **head, t_list *lst);
void    swap_a(t_list **head, t_list *l);
int		ft_atoi(const char *str);
void	mark_index(t_list **head, t_list *l);
void	push_b(t_list **head, t_list **head2);
void    push_a(t_list **head, t_list **head2);
void	retate_a(t_list **head);
void	rretate_a(t_list **head);
void	retate_b(t_list **head);
void	rretate_b(t_list **head);
void	printlst(t_list **head, t_list *l);
void	dellst(t_list *l);
void    indexing(t_list **head);
int		count(t_list *l2, int i);
void	get_first_step(t_list **head, t_list **head2, int ac);
node	*small_to_top(t_list **head);
node	*big_to_top(t_list **head);
char	scan_moves(node *s, node *b);

#endif