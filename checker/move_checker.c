/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:11:52 by abayar            #+#    #+#             */
/*   Updated: 2022/03/15 21:23:29 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_aa(t_list *l)
{
	int	temp;

	temp = l->i;
	l->i = l->next->i;
	l->next->i = temp;
}

void	push_bb(t_list **head, t_list **head2)
{
	ft_lstadd_front(head2, (*head)->i, (*head)->index);
	*head = ft_lstlast(head, *head)->next->next;
	ft_lstlast(head, *head)->next = *head;
	dellst(ft_lstlast(head, (*head)));
}

void	push_aa(t_list **head, t_list **head2)
{
	ft_lstadd_front(head, (*head2)->i, (*head2)->index);
	if (ft_lstlast(head2, (*head2)) == (*head2))
		dellst(ft_lstlast(head2, (*head2)));
	else
	{
		*head2 = ft_lstlast(head2, *head2)->next->next;
		dellst(ft_lstlast(head2, (*head2)));
	}
}

void	retate_aa(t_list **head)
{
	*head = (*head)->next;
}
