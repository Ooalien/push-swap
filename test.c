/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:16:04 by abayar            #+#    #+#             */
/*   Updated: 2022/02/21 00:15:41 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlst(t_list **head, t_list *l)
{
	if (!(*head))
		return ;
	while(l->next != *head)
		{
			printf("%d\n", l->i);
			l = l->next;
		}
		printf("%d\n", l->i);
}

int	main(int ac, char **av)
{
	t_list	*l;
	t_list	*head;
	int		c;
	int i = 2;

	
	c = ac - 1;
	
	//head = l;
	// ft_lstadd_front(&head, l);
	if (ac > 1)
	{
		l = ft_lstnew(ft_atoi(av[1]));
		head = l;
		while (i <= c)
		{
			ft_lstadd_back(&head, ft_atoi(av[i]));
			i++;
		}
		//mark_index(&head, l);
		int i = 0;
		//swap_a(&head, l);
		// printf("%d\n", ft_lstlast(&head, l)->i);
		// printf("**************************\n");
		t_list	*head2 = NULL;
		
		//push_b(&head, head2, l);
		printlst(&head, l);
		printf("******************\n");
		 //printf("%d\n", ft_lstlast(&head, l));
		push_b(&head, &head2, l);
		//push_b(&head, head2, l);
		//printf("%d\n", (*head2)->i);
		// printf("********testaat**********\n");
		// ft_lstadd_front(&head2, 8);
		// ft_lstadd_front(&head2, 5);
		// ft_lstadd_front(&head2, 9);
		printf("**********l2********\n");
		printlst(&head2, head2);
		printf("*********l1*********\n");
		//printlst(&head, head);

		// while(&(*head2)->next != head2)
		// {
		// 	printf("%d\n", (*head2)->i);
		// 	(*head2) = (*head2)->next;
		// }
		// printf("%d\n", (*head2)->i);
	}
	//printf("%d\n", ft_lstlast(&head, l)->i);
	//printf("%d\n", ft_lstsize(&l, l));
	//printf("%d\n", head->i);
	return (0);
}
