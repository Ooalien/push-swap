/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:16:04 by abayar            #+#    #+#             */
/*   Updated: 2022/03/07 21:14:36 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	printlst(t_list **head, t_list *l)
{
	if (!l)
		return ;
	while(l->next != *head)
	{
		printf("%d    index = %d   sum = %d\n", l->i, l->index, l->sum);
		l = l->next;
	}
	printf("%d    index = %d   sum = %d\n", l->i, l->index, l->sum);
}

int	main(int ac, char **av)
{
	t_list	*l;
	t_list	*head;
	node	*s;
	node	*b;
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
		int i = 0;
		t_list	*head2 = NULL;
		//printlst(&head, head);
		indexing(&head);
		get_first_step(&head, &head2, ac - 2);
		//pick_move(&head, &head2);
		while (ft_lstsize(&head2, head2) != 1)
		{
			final_step(&head, &head2);
		}
		final_step(&head,&head2);
		small_top(&head);

		//final_step(&head,&head2);
		// printf("*********l1*********\n");
		// printlst(&head, head);
		// printf("**********l2********\n");
		// printlst(&head2, head2);
		//final_step(&head,&head2);
		//final_step(&head,&head2);
		// final_step(&head,&head2);
		// final_step(&head,&head2);
		// final_step(&head,&head2);
		// final_step(&head,&head2);
		//final_step(&head,&head2);
		// printf("last move = %d\n", scan_moves(&head2, 2));
		// printf("last move = %d\n", scan_moves(&head2, 3));
		//  printf("*********l1*********\n");
		//  printlst(&head, head);
		// while(&(*head2)->next != head2)
		// {
		// 	printf("%d\n", (*head2)->i);
		// 	(*head2) = (*head2)->next;
		// }
		// printf("%d\n", (*head2)->i);
	}
	system("leaks a.out");
	//printf("%d\n", ft_lstlast(&head, l)->i);
	//printf("%d\n", ft_lstsize(&l, l));
	//printf("%d\n", head->i);
	return (0);
}
