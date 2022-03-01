/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:10:21 by abayar            #+#    #+#             */
/*   Updated: 2022/02/28 20:48:09 by abayar           ###   ########.fr       */
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
		//printf("%d     %d\n", l->i, l->index);
		l = l->next;
		l2 = l2->next;
	}
	i = l2->i;
	l2 = l2->next;
	l->index = count(l2, i);
	//printf("%d     %d\n", l->i, l->index);
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

node	*small_to_top(t_list **head)
{
	int		i;
	node	*t;
	t_list	*l;
	t_list	*l2;

	t->j = 0;
	t->y = 0;
	l = *head;
	l2 = *head;
	i = ft_lstsize(head, *head);
	//printf("%d\n", ft_lstsize(head, *head));
	while (l->next != (*head))
	{
		if (l->index < i)
			i = l->index;
		l = l->next;
	}
	if (l->index < i)
		i = l->index;
	l = l->next;
	printf ("%d\n", i);
	while (1)
	{
		retate_b(&l);
		t->j++;
		if (l->index == i)
			break;
	}
	//printf("%d    %d\n", (*head)->i, i);
	while (1)
	{
		rretate_b(&l2);
		t->y++;
		if (l2->index == i)
			break;
	}
	printf("%d    %d\n",t->j,t->y);
	return (t);
}

node	*big_to_top(t_list **head)
{
	int		i;
	node	*t;
	t_list	*l;

	t->j = 0;
	t->y = 0;
	l = *head;
	i = 0;
	//printf("%d\n",(*head)->i);
	while (l->next != (*head))
	{
		if (l->index > i)
			i = l->index;
		l = l->next;
	}
	if (l->index > i)
		i = l->index;
	l = l->next;
	printf ("%d\n", i);
	printf("%d    %d\n", (*head)->i, i);
	while (1)
	{
		retate_b(&l);
		t->j++;
		if (l->index == i)
			break;
	}
	//printf("%d    %d\n", (*head)->i, i);
	while (1)
	{
		rretate_b(head);
		t->y++;
		if ((*head)->index == i)
			break;
	}
	printf("%d    %d\n",t->j,t->y);
	return (t);
}

char	scan_moves(node *s, node *b)
{
	int	i;
	int	j;

	if (s->j > s->y)
	{
		i = s->y;
		s->s = "srr";
	}
	else
	{
		i = s->j;
		s->s = "sr";
	}
	if (b->j > b->y)
	{
		j = b->y;
		b->s = "brr";
	}
	else
	{
		j = b->j;
		b->s = "br";
	}
	if ((i + 1) > j)
		return ('b');
	else
		return ('s');
}

void	sorting(node *s, node *b, t_list **head, t_list **head2)
{
	char	c;

	c = scan_moves(s, b);
	if (c == 's')
	{
		if (s->s[2] == '\0')
		{
			while (s->j > 0)
			{
				retate_b()
				s->j--;
			}
		}
	}
}