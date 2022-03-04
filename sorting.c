/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:10:21 by abayar            #+#    #+#             */
/*   Updated: 2022/03/04 21:09:17 by abayar           ###   ########.fr       */
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

// node	*small_to_top(t_list **head)
// {
// 	int		i;
// 	node	*t;
// 	t_list	*l;
// 	t_list	*l2;

// 	t->j = 0;
// 	t->y = 0;
// 	l = *head;
// 	l2 = *head;
// 	i = ft_lstsize(head, *head);
// 	//printf("%d\n", ft_lstsize(head, *head));
// 	while (l->next != (*head))
// 	{
// 		if (l->index < i)
// 			i = l->index;
// 		l = l->next;
// 	}
// 	if (l->index < i)
// 		i = l->index;
// 	l = l->next;
// 	printf ("%d\n", i);
// 	while (1)
// 	{
// 		retate_b(&l);
// 		t->j++;
// 		if (l->index == i)
// 			break;
// 	}
// 	//printf("%d    %d\n", (*head)->i, i);
// 	while (1)
// 	{
// 		rretate_b(&l2);
// 		t->y++;
// 		if (l2->index == i)
// 			break;
// 	}
// 	printf("%d    %d\n",t->j,t->y);
// 	return (t);
// }

// node	*big_to_top(t_list **head)
// {
// 	int		i;
// 	node	*t;
// 	t_list	*l;

// 	t->j = 0;
// 	t->y = 0;
// 	l = *head;
// 	i = 0;
// 	//printf("%d\n",(*head)->i);
// 	while (l->next != (*head))
// 	{
// 		if (l->index > i)
// 			i = l->index;
// 		l = l->next;
// 	}
// 	if (l->index > i)
// 		i = l->index;
// 	l = l->next;
// 	printf ("%d\n", i);
// 	printf("%d    %d\n", (*head)->i, i);
// 	while (1)
// 	{
// 		retate_b(&l);
// 		t->j++;
// 		if (l->index == i)
// 			break;
// 	}
// 	//printf("%d    %d\n", (*head)->i, i);
// 	while (1)
// 	{
// 		rretate_b(head);
// 		t->y++;
// 		if ((*head)->index == i)
// 			break;
// 	}
// 	printf("%d    %d\n",t->j,t->y);
// 	return (t);
// }

// char	scan_moves(node *s, node *b)
// {
// 	int	i;
// 	int	j;

// 	if (s->j > s->y)
// 	{
// 		i = s->y;
// 		s->s = "srr";
// 	}
// 	else
// 	{
// 		i = s->j;
// 		s->s = "sr";
// 	}
// 	if (b->j > b->y)
// 	{
// 		j = b->y;
// 		b->s = "brr";
// 	}
// 	else
// 	{
// 		j = b->j;
// 		b->s = "br";
// 	}
// 	if ((i + 1) > j)
// 		return ('b');
// 	else
// 		return ('s');
// }

// void	sorting(node *s, node *b, t_list **head, t_list **head2)
// {
// 	char	c;

// 	c = scan_moves(s, b);
// 	if (c == 's')
// 	{
// 		if (s->s[2] == '\0')
// 		{
// 			while (s->j > 0)
// 			{
// 				retate_b(head2);
// 				s->j--;
// 			}
// 		}
// 		else
// 		{
// 			while (s->y > 0)
// 			{
// 				rretate_b(head2);
// 				s->y--;
// 			}
// 		}
// 		push_a(head, head2);
// 		retate_b(head2);
// 	}
// 	else
// 	{
// 		if (b->s[2] == '\0')
// 		{
// 			while (b->j > 0)
// 			{
// 				retate_b(head2);
// 				b->j--;
// 			}
// 		}
// 		else
// 		{
// 			while (b->y > 0)
// 			{
// 				rretate_b(head2);
// 				b->y--;
// 			}
// 		}
// 		push_a(head, head2);
// 	}
// }

int	scan_moves(t_list **head, int index)
{
	t_list	*l, *l2;
	int		i;
	int		j;
	int		y;

	i = 0;
	j = 0;
	l = *head;
	l2 = *head;
	while (l->next != (*head))
	{
		//printf("%d\n", l->i);
		if (l->index == index)
			break ;
		l = l->next;	
	}
	i = l->i;
	while (1)
	{
		if (l2->i == i)
			break ;
		retate(&l2);
		j++;
	}
	l2 = *head;
	y = 0;
	while (1)
	{
		if (l2->i == i)
			break ;
		rretate(&l2);
		y++;
	}
	if (y < j)
		return (y);
	return (j);
}

void	calc_move(t_list **head)
{
	t_list	*l;

	l = *head;
	while(l->next != *head)
	{
		l->moves = scan_moves(head, l->index);
		//printf("%d    index = %d   moves = %d\n", l->i, l->index, l->moves);
		l = l->next;
	}
	l->moves = scan_moves(head, l->index);
	//printf("%d    index = %d   moves = %d\n", l->i, l->index, l->moves);
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
		if(l->index == (index + 1))
			return (scan_moves(head, l->index));
		l = l->next;
	}
	return(scan_moves(head, l->index));
}

void	pos_list(t_list **head)
{
	t_list *l;
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

int	pick_move(t_list **head, t_list **head2)
{
	t_list	*l;
	int		r;
	
	l = *head2;
	r = ft_lstsize(head2, *head2);
	pos_list(head2);
	while (l->next != *head2)
	{
		l->sum = scan_moves(head2, l->index) + select_pair(head, l->index);
		l = l->next;
	}
	l->sum = scan_moves(head, l->index) + select_pair(head2, l->index);
	l = l->next;
	while (l->next != *head2)
	{
		if (l->sum < r)
			r = l->pos;
		l = l->next;
	}
	return (r);
}

void	final_step(t_list **head, t_list **head2)
{
	int move;
	 
	move = pick_move(head, head2);
	while (1)
	{
		if (move <= ((ft_lstsize(head2, *head2) / 2) + 1))
		{
			if((*head2)->pos == move)
				break ;
			retate_b(head2);
			//continue ;
		}
		else
		{
			if((*head2)->pos == move)
				break ;
			rretate_b(head2);
		}
	}
	// move = scan_moves(head, );
	// printf("select pair = %d\n", move);
	// while (1)
	// {
	// 	if (move <= ((ft_lstsize(head, *head) / 2) + 1))
	// 	{
	// 		if((*head)->moves == move)
	// 			break ;
	// 		retate_a(head);
			
	// 		//continue ;
	// 	}
	// 	else
	// 	{
	// 		if((*head)->moves == move)
	// 			break ;
	// 		rretate_a(head);
	// 	}
	// }
	// push_a(head, head2);
}
