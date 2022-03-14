/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:21:45 by abayar            #+#    #+#             */
/*   Updated: 2022/03/14 15:05:52 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numbers(t_list **head)
{
	t_list	*l;

	l = *head;
	if (l->index == 0 && l->next->index == 1)
		return ;
	else if (l->index == 0 && l->next->index == 2)
	{
		rretate_a(head);
		swap_a(*head);
	}
	else if (l->index == 1 && l->next->index == 2)
		rretate_a(head);
	else if (l->index == 1 && l->next->index == 0)
		swap_a(*head);
	else if (l->index == 2 && l->next->index == 0)
		retate_a(head);
	else if (l->index == 2 && l->next->index == 1)
	{
		retate_a(head);
		swap_a(*head);
	}
}

void	for_numbers(t_list **head, t_list **head2)
{
	small_top(head);
	push_b(head, head2);
	indexing(head);
	three_numbers(head);
	push_a(head, head2);
}

void	five_numbers(t_list **head, t_list **head2)
{
	small_top(head);
	push_b(head, head2);
	indexing(head);
	for_numbers(head, head2);
	push_a(head, head2);
}

void	two_numbers(t_list **h)
{
	if ((*h)->i > (*h)->next->i)
		retate_a(h);
}
