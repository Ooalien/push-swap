/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:35:15 by abayar            #+#    #+#             */
/*   Updated: 2022/02/20 23:40:05 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				i;
	int				index;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **alst, int data);
void	ft_lstadd_front(t_list **alst, int data);
t_list	*ft_lstlast(t_list **head, t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list **head, t_list *lst);
void    swap_a(t_list **head, t_list *l);
int		ft_atoi(const char *str);
void	mark_index(t_list **head, t_list *l);
void	push_b(t_list **head, t_list **head2, t_list *l);
void	printlst(t_list **head, t_list *l);
void	dellst(t_list *l);

#endif