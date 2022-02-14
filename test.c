/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:16:04 by abayar            #+#    #+#             */
/*   Updated: 2022/02/14 20:17:58 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*l;
	t_list	*head;
	int		c;
	int i = 2;

	
	c = ac - 1;
	l = ft_lstnew(ft_atoi(av[1]));
	head = l;
	// ft_lstadd_front(&head, l);
	while (i <= c)
	{
		ft_lstadd_back(&head, ft_atoi(av[i]));
		i++;
	}
	//int i = 0;
	while(l->next != head)
	{
		printf("%d\n", l->i);
		l = l->next;
		i++;
	}
	printf("%d\n", l->i);
	//printf("%d\n", ft_lstlast(&head, l)->i);
	
	//printf("%d\n", ft_lstsize(&l, l));
	//printf("%d\n", head->i);
	return (0);
}
