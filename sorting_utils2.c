/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:37:04 by abayar            #+#    #+#             */
/*   Updated: 2022/03/21 17:45:12 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count(t_list *l2, int i)
{
	int	j;

	j = 0;
	while (l2->i != i)
	{
		if (l2->i < i)
			j++;
		l2 = l2->next;
	}
	return (j);
}

void	indexing(t_list **head)
{
	int		i;
	int		j;
	t_list	*l;
	t_list	*l2;

	l = *head;
	l2 = *head;
	while (l->next != *head)
	{
		j = 0;
		i = l->i;
		l2 = l2->next;
		while (l2->i != i)
		{
			if (l2->i < i)
				j++;
			l2 = l2->next;
		}
		l->index = j;
		l = l->next;
		l2 = l2->next;
	}
	i = l2->i;
	l2 = l2->next;
	l->index = count(l2, i);
}

void	get_first_step(t_list **head, t_list **head2, int ac)
{
	t_list	*l;
	int		p;

	p = 0;
	l = *head;
	while (p <= ac)
	{
		if ((l->index == 0 || l->index == ac))
			retate_a(head);
		else if (l->index != 0 || l->index != ac)
			push_b(head, head2);
		l = l->next;
		p++;
	}
}

int	lst_chr(t_list **head, int index)
{
	t_list	*l;
	int		i;

	l = *head;
	i = 500;
	while (l->next != *head)
	{
		if ((l->index > index) && (l->index < i))
			i = l->index;
		l = l->next;
	}
	if ((l->index > index) && (l->index < i))
		i = l->index;
	return (i);
}
