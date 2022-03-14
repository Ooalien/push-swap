/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:10:21 by abayar            #+#    #+#             */
/*   Updated: 2022/03/14 14:56:14 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pick_utils(t_list **head, t_list **head2)
{
	t_list	*l;

	l = *head2;
	while (l->next != *head2)
	{
		l->sum = scan_moves(head2, l->index)
			+ select_pair(head, lst_chr(head, l->index));
		l = l->next;
	}
	l->sum = scan_moves(head2, l->index)
		+ select_pair(head, lst_chr(head, l->index));
	l = l->next;
}

int	pick_move(t_list **head, t_list **head2)
{
	int		r;
	t_list	*l;

	r = 500;
	l = *head2;
	pos_list(head2);
	pick_utils(head, head2);
	if (ft_lstsize(head, (*head)) == 1)
		return (l->sum);
	else if (ft_lstsize(head, (*head)) == 2)
	{
		if (l->sum < l->next->sum)
			return (l->sum);
		return (l->next->sum);
	}
	while (l->next != *head2)
	{
		if (l->sum < r)
			r = l->sum;
		l = l->next;
	}
	if (l->sum < r)
		r = l->sum;
	return (r);
}

void	final_step_utils(t_list **head, int move, int i)
{
	while (1)
	{
		if (i <= ((ft_lstsize(head, *head) / 2) + 1))
		{
			if ((*head)->index == move)
				break ;
			retate_a(head);
		}
		else
		{
			if ((*head)->index == move)
				break ;
			rretate_a(head);
		}	
	}
}

void	final_step(t_list **head, t_list **head2)
{
	int	move;
	int	i;

	move = pick_move(head, head2);
	i = pos_nod_utils(head2, move);
	while (1)
	{
		if (i <= ((ft_lstsize(head2, *head2) / 2) + 1))
		{
			if ((*head2)->sum == move)
				break ;
			retate_b(head2);
		}
		else
		{
			if ((*head2)->sum == move)
				break ;
			rretate_b(head2);
		}
	}
	move = lst_chr(head, (*head2)->index);
	i = pos_nod(head, move);
	final_step_utils(head, move, i);
	push_a(head, head2);
}
