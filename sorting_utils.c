/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:30:20 by abayar            #+#    #+#             */
/*   Updated: 2022/03/10 16:31:07 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_nod(t_list **head, int index)
{
	t_list	*l;

	l = *head;
	pos_list(head);
	while (l->next != *head)
	{
		if (index == l->index)
			return (l->pos);
		l = l->next;
	}
	return (l->pos);
}

int	pos_nod_utils(t_list **head, int sum)
{
	t_list	*l;

	l = *head;
	pos_list(head);
	while (l->next != *head)
	{
		if (sum == l->sum)
			return (l->pos);
		l = l->next;
	}
	return (l->pos);
}

void	calc_move(t_list **head)
{
	t_list	*l;

	l = *head;
	while (l->next != *head)
	{
		l->moves = scan_moves(head, l->index);
		l = l->next;
	}
	l->moves = scan_moves(head, l->index);
}

int	select_pair(t_list **head, int index)
{
	int		i;
	t_list	*l;

	i = 0;
	l = *head;
	pos_list(head);
	while (l->next != *head)
	{
		if (l->index == index)
			return (scan_moves(head, l->index));
		l = l->next;
	}
	return (scan_moves(head, l->index));
}

void	pos_list(t_list **head)
{
	t_list	*l;
	int		i;

	i = 1;
	l = *head;
	while (l->next != *head)
	{
		l->pos = i;
		i++;
		l = l->next;
	}
	l->pos = i;
}
