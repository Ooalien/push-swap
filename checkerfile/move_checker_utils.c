/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_checker_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:13:05 by abayar            #+#    #+#             */
/*   Updated: 2022/03/21 14:33:39 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rretate_aa(t_list **head)
{
	if (!(*head))
		return ;
	*head = ft_lstlast(head, *head);
}

void	retate_bb(t_list **head)
{
	if (!(*head))
		return ;
	*head = (*head)->next;
}

void	rretate_bb(t_list **head)
{
	if (!(*head))
		return ;
	*head = ft_lstlast(head, *head);
}

// void	retatee(t_list **head)
// {
// 	*head = (*head)->next;
// }

// void	rretatee(t_list **head)
// {
// 	*head = ft_lstlast(head, *head);
// }
