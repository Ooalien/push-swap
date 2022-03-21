/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:35:49 by abayar            #+#    #+#             */
/*   Updated: 2022/03/21 15:36:09 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	do_moves_utils(t_list **head, t_list **head2, char *s)
{
	if (ft_strcmp(s, "pb\n") == 0)
		push_bb(head, head2);
	else if (ft_strcmp(s, "ss\n") == 0)
	{
		swap_aa(*head);
		swap_aa(*head2);
	}
	else if (ft_strcmp(s, "rr\n") == 0)
	{
		retate_aa(head);
		retate_bb(head2);
	}
	else if (ft_strcmp(s, "rrr\n") == 0)
	{
		rretate_aa(head);
		rretate_bb(head2);
	}
}

void	do_moves(t_list **head, t_list **head2, char *s)
{
	if (!s)
		return ;
	if (ft_strcmp(s, "sa\n") == 0)
		swap_aa(*head);
	else if (ft_strcmp(s, "sb\n") == 0)
		swap_aa(*head2);
	else if (ft_strcmp(s, "ra\n") == 0)
		retate_aa(head);
	else if (ft_strcmp(s, "rb\n") == 0)
		retate_bb(head2);
	else if (ft_strcmp(s, "rra\n") == 0)
		rretate_aa(head);
	else if (ft_strcmp(s, "rrb\n") == 0)
		rretate_bb(head2);
	else if (ft_strcmp(s, "pa\n") == 0)
		push_aa(head, head2);
	do_moves_utils(head, head2, s);
}
