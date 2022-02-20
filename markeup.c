/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   markeup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:57:42 by abayar            #+#    #+#             */
/*   Updated: 2022/02/18 19:15:33 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	mark_index(t_list **head, t_list *l)
{
	int	i;

	i = ft_lstsize(head,*head);
	
	while(l->next != *head)
		{
			printf("%d\n", l->i);
			l = l->next;
		}
	// head = &(*head)->next;
	//printf("%d\n", (*head)->i);
}