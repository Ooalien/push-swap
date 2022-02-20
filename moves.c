/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 23:03:48 by abayar            #+#    #+#             */
/*   Updated: 2022/02/21 00:16:54 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    swap_a(t_list **head, t_list *l)
{
	int temp;

	temp = l->i;
	l->i = l->next->i;
	l->next->i = temp;
}

void    push_b(t_list **head, t_list **head2, t_list *l)
{
	t_list  *l2;

	ft_lstadd_front(head2, l->i);
	*head2 = ft_lstlast(head, l)->next->next;
	printf("%ddffdgd\n", ft_lstlast(head, l)->i);
	ft_lstlast(head, l)->next = ft_lstlast(head, l)->next->next;
   
   //dellst(l);
   // printf("%d\n", l2->i);
	// head2 = &l;
	// head = &(*head)->next;
	// l->next = l;
	// ft_lstlast(head, *head)->next = *head;
}