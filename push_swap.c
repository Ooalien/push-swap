/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:16:04 by abayar            #+#    #+#             */
/*   Updated: 2022/03/21 19:04:43 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	hard_code(t_list **head, t_list **head2, int i)
{
	if (i == 2)
		two_numbers(head);
	else if (i == 3)
		three_numbers(head);
	else if (i == 4)
		for_numbers(head, head2);
	else if (i == 5)
		five_numbers(head, head2);
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

void	push_swap(t_list **head, t_list **head2, int ac)
{
	get_first_step(head, head2, ac - 2);
	while (ft_lstsize(head2, *head2) != 1)
	{
		final_step(head, head2);
	}
	final_step(head, head2);
	small_top(head);
}

void	push_swap_utils(t_list **head, t_list **head2, char **av, int ac)
{
	int	i;
	int	c;

	c = ac - 1;
	i = 2;
	*head = ft_lstnew(ft_atoi(av[1]));
	while (i <= c)
	{
		ft_lstadd_back(head, ft_atoi(av[i]));
		i++;
	}
	if (is_sorted(head) == 1)
		return ;
	i = ft_lstsize(head, *head);
	indexing(head);
	if (i <= 5)
	{
		hard_code(head, head2, i);
		return ;
	}
	push_swap(head, head2, ac);
}

int	main(int ac, char **av)
{
	t_list	*head;
	t_list	*head2;

	head2 = NULL;
	if (check_args(av) == 0 || check_rep(av) == 0)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (ac > 1)
	{
		push_swap_utils(&head, &head2, av, ac);
	}
	return (0);
}
