/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:03:48 by abayar            #+#    #+#             */
/*   Updated: 2022/03/21 17:44:18 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_list *l)
{
	int	temp;

	temp = l->i;
	l->i = l->next->i;
	l->next->i = temp;
	write(1, "sa\n", 3);
}

void	push_b(t_list **head, t_list **head2)
{
	ft_lstadd_front(head2, (*head)->i, (*head)->index);
	*head = ft_lstlast(head, *head)->next->next;
	ft_lstlast(head, *head)->next = *head;
	dellst(ft_lstlast(head, (*head)));
	write(1, "pb\n", 3);
}

void	push_a(t_list **head, t_list **head2)
{
	ft_lstadd_front(head, (*head2)->i, (*head2)->index);
	if (ft_lstlast(head2, (*head2)) == (*head2))
		dellst(ft_lstlast(head2, (*head2)));
	else
	{
		*head2 = ft_lstlast(head2, *head2)->next->next;
		dellst(ft_lstlast(head2, (*head2)));
	}
	write(1, "pa\n", 3);
}

void	retate_a(t_list **head)
{
	*head = (*head)->next;
	write(1, "ra\n", 3);
}
