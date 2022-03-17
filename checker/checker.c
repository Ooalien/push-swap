/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:21:57 by abayar            #+#    #+#             */
/*   Updated: 2022/03/17 21:42:22 by abayar           ###   ########.fr       */
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

int	is_sorted(t_list **head)
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

char	*is_move(char *s)
{
	if (!s)
		return (0);
	if (ft_strcmp(s, "sa\n") == 0)
		return (s);
	else if (ft_strcmp(s, "sb\n") == 0)
		return (s);
	else if (ft_strcmp(s, "ra\n") == 0)
		return (s);
	else if (ft_strcmp(s, "rb\n") == 0)
		return (s);
	else if (ft_strcmp(s, "rra\n") == 0)
		return (s);
	else if (ft_strcmp(s, "rrb\n") == 0)
		return (s);
	else if (ft_strcmp(s, "pa\n") == 0)
		return (s);
	else if (ft_strcmp(s, "pb\n") == 0)
		return (s);
	else if (ft_strcmp(s, "ss\n") == 0)
		return (s);
	else if (ft_strcmp(s, "rr\n") == 0)
		return (s);
	else if (ft_strcmp(s, "rrr\n") == 0)
		return (s);
	else
	{
		write(2, "Error\n", 6);
		exit(0);
	}
	return (0);
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
	else if (ft_strcmp(s, "pb\n") == 0)
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

int main(int ac, char **av)
{
	t_list	*l;
	t_list	*head;
	int		c;
	int		i;
	t_list	*head2;
	char	*s, *temp;

	s = NULL;
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
		while ((s = get_next_line(0)) != NULL)
		{
			if (is_sorted(&head) == 1 && ft_lstsize(&head, head) == ac - 1)
			{
				write(1, "OK\n", 3);
				free(s);
				return (0);
			}
			temp = s;
			s = is_move(s);
			free(temp);
			do_moves(&head, &head2, is_move(s));
			if (is_sorted(&head) == 1 && ft_lstsize(&head, head) == ac - 1)
			{
				write(1, "OK\n", 3);
				free(s);
				return (0);
			}
		}
		write(1, "KO\n", 3);
	}
	free(s);
	system("leaks a.out");
	return (0);
}