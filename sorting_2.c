/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:08:08 by abayar            #+#    #+#             */
/*   Updated: 2022/03/21 15:08:25 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	final_step_utils_2(t_list **head2, int i, int move, t_node *n)
{
	while (1)
	{
		if (i <= ((ft_lstsize(head2, *head2) / 2) + 1))
		{
			if ((*head2)->sum == move)
				break ;
			retate(head2);
			n->rb++;
		}
		else
		{
			if ((*head2)->sum == move)
				break ;
			rretate(head2);
			n->rrb++;
		}
	}
}

void	final_step(t_list **head, t_list **head2)
{
	int		move;
	int		i;
	t_node	n;

	move = pick_move(head, head2);
	i = pos_nod_utils(head2, move);
	n.rrb = 0;
	n.rb = 0;
	final_step_utils_2(head2, i, move, &n);
	move = lst_chr(head, (*head2)->index);
	i = pos_nod(head, move);
	final_step_utils(head, move, i, &n);
	print_opti(&n);
	push_a(head, head2);
}
