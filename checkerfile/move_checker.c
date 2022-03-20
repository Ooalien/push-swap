/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:11:52 by abayar            #+#    #+#             */
/*   Updated: 2022/03/19 21:12:31 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_aa(t_list *l)
{
	if (!l)
		return ;
	int	temp;

	temp = l->i;
	l->i = l->next->i;
	l->next->i = temp;
}

void	push_bb(t_list **head, t_list **head2)
{
	t_list *tmp = *head;
	t_list *last_a;
	t_list *last_b;
	if (!(*head))
		return ;
	
	last_a = ft_lstlast(head, (*head));
	last_a->next = tmp->next;
	*head = tmp->next;
	if(!(*head2))
	{
		(*head2) = tmp;
		tmp->next = tmp;
		return ;
	}
	last_b = ft_lstlast(head2, (*head2));
	last_b->next = tmp;
	tmp->next = *head2;
	*head2 = tmp;
}

void	push_aa(t_list **head, t_list **head2)
{	
	t_list *tmp = *head2;
	t_list *last_a;
	t_list *last_b;
	if (!(*head2))
		return ;
	last_b = ft_lstlast(head2, (*head2));
	last_b->next = tmp->next;
	*head2 = tmp->next;
	if(!(*head))
	{
		(*head) = tmp;
		tmp->next = tmp;
		return ;
	}
	last_a = ft_lstlast(head, (*head));
	last_a->next = tmp;
	tmp->next = *head;
	*head = tmp;
}

void	retate_aa(t_list **head)
{
	*head = (*head)->next;
}
