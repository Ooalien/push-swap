/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:55:04 by abayar            #+#    #+#             */
/*   Updated: 2022/03/14 15:03:15 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	scan_utils(t_list **head, int i, int j, int y)
{
	t_list	*l2;

	l2 = *head;
	while (1)
	{
		if (l2->i == i)
			break ;
		retate(&l2);
		j++;
	}
	l2 = *head;
	y = 0;
	while (1)
	{
		if (l2->i == i)
			break ;
		rretate(&l2);
		y++;
	}
}

int	scan_moves(t_list **head, int index)
{
	t_list	*l;
	t_list	*l2;
	int		i;
	int		j;
	int		y;

	i = 0;
	j = 0;
	y = 0;
	l = *head;
	l2 = *head;
	while (l->next != (*head))
	{
		if (l->index == index)
			break ;
		l = l->next;
	}
	i = l->i;
	scan_utils(head, i, j, y);
	if (y < j)
		return (y);
	return (j);
}

void	small_top_utils(t_list **head, int p)
{
	while (1)
	{
		if (p <= ((ft_lstsize(head, *head) / 2) + 1))
		{
			if ((*head)->index == 0)
				break ;
			retate_a(head);
		}
		else
		{
			if ((*head)->index == 0)
				break ;
			rretate_a(head);
		}
	}
}

void	small_top(t_list **head)
{
	t_list	*l;
	int		p;

	l = *head;
	pos_list(head);
	while (l->next != *head)
	{
		if (l->index == 0)
			p = l->pos;
		l = l->next;
	}
	if (l->index == 0)
			p = l->pos;
	l = l->next;
	small_top_utils(head, p);
}
