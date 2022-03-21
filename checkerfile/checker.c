/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:21:57 by abayar            #+#    #+#             */
/*   Updated: 2022/03/21 19:04:45 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line.h"

int	is_sorted(t_list **head)
{
	t_list	*l;

	if (!(*head))
		return (0);
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
	if ((ft_strcmp(s, "sa\n") == 0) || (ft_strcmp(s, "sb\n") == 0))
		return (s);
	else if ((ft_strcmp(s, "ra\n") == 0) || (ft_strcmp(s, "rb\n") == 0))
		return (s);
	else if (ft_strcmp(s, "rra\n") == 0)
		return (s);
	else if (ft_strcmp(s, "rrb\n") == 0)
		return (s);
	else if ((ft_strcmp(s, "pa\n") == 0) || (ft_strcmp(s, "pb\n") == 0))
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

void	checker_utils(t_list **head, char **av, int c)
{
	int	i;

	i = 2;
	while (i <= c)
	{
		ft_lstadd_back(head, ft_atoi(av[i]));
		i++;
	}
}

void	checker(t_list **head, t_list **head2, char **av, int ac)
{
	int		c;
	char	*s;

	s = NULL;
	c = ac - 1;
	*head = ft_lstnew(ft_atoi(av[1]));
	checker_utils(head, av, c);
	s = get_next_line(0);
	while (s != NULL)
	{
		do_moves(head, head2, is_move(s));
		free(s);
		s = NULL;
		s = get_next_line(0);
	}
	if (is_sorted(head) == 1 && ft_lstsize(head, *head) == ac - 1)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (s)
		free(s);
}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*head2;

	head2 = NULL;
	head = NULL;
	if (check_args(av) == 0 || check_rep(av) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ac > 1)
	{
		checker(&head, &head2, av, ac);
	}
	return (0);
}
