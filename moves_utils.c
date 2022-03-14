/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:45:23 by abayar            #+#    #+#             */
/*   Updated: 2022/03/10 17:45:49 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rretate_a(t_list **head)
{
	*head = ft_lstlast(head, *head);
	write(1, "rra\n", 4);
}

void	retate_b(t_list **head)
{
	*head = (*head)->next;
	write(1, "rb\n", 3);
}

void	rretate_b(t_list **head)
{
	*head = ft_lstlast(head, *head);
	write(1, "rrb\n", 4);
}

void	retate(t_list **head)
{
	*head = (*head)->next;
}

void	rretate(t_list **head)
{
	*head = ft_lstlast(head, *head);
}
