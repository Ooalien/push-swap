/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:21:57 by abayar            #+#    #+#             */
/*   Updated: 2022/03/15 18:29:23 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

void	printls(t_list **head, t_list *l)
{
	while (l->next != (*head))
	{
		printf("%d\n", l->i);
		l = l->next;
	}
	printf("%d\n", l->i);
}

int	is_sorted(t_list **head, t_list **head2)
{
	t_list	*l;

	l = *head;
	while (l->next != *head)
	{
		if (l->i > l->next->i)
			return (0);
		l = l->next;
	}
	return (1);
}

void	do_moves(t_list **head, t_list **head2, char *s)
{
	if (ft_strcmp(s, "sa\n") == 0)
		swap_a(*head);
	else if (ft_strcmp(s, "sb\n") == 0)
		swap_a(*head2);
	else if (ft_strcmp(s, "ra\n") == 0)
		retate_a(head);
	else if (ft_strcmp(s, "rb\n") == 0)
		retate_b(head2);
	else if (ft_strcmp(s, "rra\n") == 0)
		rretate_a(head);
	else if (ft_strcmp(s, "rrb\n") == 0)
		rretate_b(head2);
	else if (ft_strcmp(s, "ss\n") == 0)
	{
		swap_a(*head);
		swap_a(*head2);
	}
	else if (ft_strcmp(s, "rr\n") == 0)
	{
		retate_a(head);
		retate_b(head2);
	}
	else if (ft_strcmp(s, "rrr\n") == 0)
	{
		rretate_a(head);
		rretate_b(head2);
	}
}

int main(int ac, char **av)
{
	t_list	*l;
	t_list	*head;
	int		c;
	int		i;
	t_list	*head2;

	c = ac - 1;
	i = 2;
	head2 = NULL;
	head = NULL;
	if (check_args(av) == 0 || check_rep(av) == 0)
		return (0);
	if (ac > 1)
	{
		l = ft_lstnew(ft_atoi(av[1]));
		head = l;
		while (i <= c)
		{
			ft_lstadd_back(&head, ft_atoi(av[i]));
			i++;
		}
		//printls(&head, head);
		while (1)
		{
			if (is_sorted(&head, &head2) == 1)// && ft_lstsize(&head, head) == ac - 1)
			{
				write(1, "OK\n", 3);
				return (0);
			}
			//printf("%s\n", get_next_line(0));
			do_moves(&head, &head2, get_next_line(0));
			//printls(&head, head);
		}
	}
	//system("leaks a.out");
}