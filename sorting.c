/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:10:21 by abayar            #+#    #+#             */
/*   Updated: 2022/03/17 00:20:11 by abayar           ###   ########.fr       */
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

void	print_opti_utils(t_node *n)
{
	while (n->rra > 0 || n->rrb > 0)
	{
		if (n->rra > 0 && n->rrb > 0)
		{
			write(1, "rrr\n", 4);
			n->rra--;
			n->rrb--;
		}
		else if (n->rra > 0)
		{
			write(1, "rra\n", 4);
			n->rra--;
		}
		else if (n->rrb > 0)
		{
			write(1, "rrb\n", 4);
			n->rrb--;
		}
	}
}

void	print_opti(t_node *n)
{
	while (n->ra > 0 || n->rb > 0)
	{
		if (n->ra > 0 && n->rb > 0)
		{
			write(1, "rr\n", 3);
			n->ra--;
			n->rb--;
		}
		else if (n->ra > 0)
		{
			write(1, "ra\n", 3);
			n->ra--;
		}
		else if (n->rb > 0)
		{
			write(1, "rb\n", 3);
			n->rb--;
		}
	}
	print_opti_utils(n);
}

void	final_step_utils(t_list **head, int move, int i, t_node *n)
{
	n->rra = 0;
	n->ra = 0;
	while (1)
	{
		if (i <= ((ft_lstsize(head, *head) / 2) + 1))
		{
			if ((*head)->index == move)
				break ;
			retate(head);
			n->ra++;
		}
		else
		{
			if ((*head)->index == move)
				break ;
			rretate(head);
			n->rra++;
		}	
	}
}

void	final_step(t_list **head, t_list **head2)
{
	int	move;
	int	i;
	t_node	n;

	move = pick_move(head, head2);
	i = pos_nod_utils(head2, move);
	n.rrb = 0;
	n.rb = 0;
	while (1)
	{
		if (i <= ((ft_lstsize(head2, *head2) / 2) + 1))
		{
			if ((*head2)->sum == move)
				break ;
			retate(head2);
			n.rb++;
		}
		else
		{
			if ((*head2)->sum == move)
				break ;
			rretate(head2);
			n.rrb++;
		}
	}
	move = lst_chr(head, (*head2)->index);
	i = pos_nod(head, move);
	final_step_utils(head, move, i, &n);
	print_opti(&n);
	push_a(head, head2);
}
