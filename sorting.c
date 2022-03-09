/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 17:10:21 by abayar            #+#    #+#             */
/*   Updated: 2022/03/09 20:03:12 by abayar           ###   ########.fr       */
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
		if(l->index == index)
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
/*
* kjkjk
*/
int	pick_move(t_list **head, t_list **head2)
{
	t_list	*l;
	int		r;
	
	l = *head2;
	r = 500;//ft_lstsize(head2, *head2);
	pos_list(head2);
	//printf("%d\n",select_pair(head, lst_chr(head, l->index)));
	while (l->next != *head2)
	{
		l->sum = scan_moves(head2, l->index) + select_pair(head, lst_chr(head, l->index));
		l = l->next;
	}
	l->sum = scan_moves(head2, l->index) + select_pair(head, lst_chr(head, l->index));
	l = l->next;
	if (ft_lstsize(head, (*head)) == 1)
		return(l->sum);
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

int	pos_nod(t_list **head, int index)
{
	t_list	*l;

	l = *head;
	pos_list(head);
	while (l->next != *head)
	{
		if (index == l->index)
			return(l->pos);
		l = l->next;
	}
	return(l->pos);
}

int	pos_nod_utils(t_list **head, int sum)
{
	t_list	*l;

	l = *head;
	pos_list(head);
	while (l->next != *head)
	{
		if (sum == l->sum)
			return(l->pos);
		l = l->next;
	}
	return(l->pos);
}

void	final_step(t_list **head, t_list **head2)
{
	int move;
	int	i;
	 
	move = pick_move(head, head2);
	i = pos_nod_utils(head2, move);
	while (1)
	{
		if (i <= ((ft_lstsize(head2, *head2) / 2) + 1))
		{
			if((*head2)->sum == move)
				break ;
			retate_b(head2);
			//continue ;
		}
		else
		{
			if((*head2)->sum == move)
				break ;
			rretate_b(head2);
		}
	}
	//printf("head a  = %d\n", (*head)->i);
	move = lst_chr(head, (*head2)->index);
	i = pos_nod(head, move);
	//i = pos_nod(head2, );
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
	push_a(head, head2);
}

void	small_top(t_list **head)
{
	t_list	*l;
	int		p;

	l = *head;
	pos_list(head);
	while (l->next != *head)
	{
		if (l->index == 0)
			p = l->pos;
		l = l->next;
	}
	if (l->index == 0)
			p = l->pos;
	l = l->next;
	while (1)
	{
		if (p <= ((ft_lstsize(head, *head) / 2) + 1))
		{
			if ((*head)->index == 0)
				break;
			retate_a(head);
		}
		else
		{
			if ((*head)->index == 0)
				break;
			rretate_a(head);
		}
	}
}