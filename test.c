/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:16:04 by abayar            #+#    #+#             */
/*   Updated: 2022/03/05 22:16:01 by abayar           ###   ########.fr       */
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
		//mark_index(&head, l);
		int i = 0;
		//swap_a(&head, l);
		// printf("%d\n", ft_lstlast(&head, l)->i);
		// printf("**************************\n");
		t_list	*head2 = NULL;
		
		//push_b(&head, head2, l);
		printlst(&head, head);
		//printf("******************\n");
		 //printf("%d\n", ft_lstlast(&head, l));
		// push_b(&head, &head2);
		// push_b(&head, &head2);
		// push_b(&head, &head2);
		// push_a(&head, &head2);
		// push_a(&head, &head2);
		// push_a(&head, &head2);
		//retate_a(&head);

		// rretate_b(&head2);
		
		//push_a(&head, &head2);
		//rretate_b(&head2);
		//printf("%d\n", (*head2)->i);
		// printf("********testaat**********\n");
		// ft_lstadd_front(&head2, 8);
		// ft_lstadd_front(&head2, 5);
		// ft_lstadd_front(&head2, 9);
		indexing(&head);
		get_first_step(&head, &head2, ac - 2);
		printf("**********l2********\n");
		printlst(&head2, head2);
		
		//printf("last node; %d\n", ft_lstlast(&head2,head2)->i);
		printf("*********l1*********\n");
		printlst(&head, head);
		// printf("********* check *********\n");
		//s = small_to_top(&head2);
		// printf("********* check *********\n");
		//b = big_to_top(&head2);
		//scan_moves(s, b);
		//sorting(s,b,&head,&head2);
		printf("******************\n");
		// printlst(&head2, head2);
		calc_move(&head2);
		pick_move(&head, &head2);
		//printlst(&head2, head2);
		//printf("5 moves = %d  ||   next to 5 moves = %d\n", scan_moves(&head2, 5), select_pair(&head,5));
		final_step(&head,&head2);
		printf("*********l1*********\n");
		printlst(&head, head);
		printf("**********l2********\n");
		printlst(&head2, head2);
		
		final_step(&head,&head2);
		printf("*********l1*********\n");
		printlst(&head, head);
		printf("**********l2********\n");
		printlst(&head2, head2);
		final_step(&head,&head2);
		final_step(&head,&head2);
		final_step(&head,&head2);
		final_step(&head,&head2);
		final_step(&head,&head2);
		final_step(&head,&head2);
		//final_step(&head,&head2);
		printf("*********l1*********\n");
		printlst(&head, head);
		printf("**********l2********\n");
		printlst(&head2, head2);
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
	//system("leaks a.out");
	//printf("%d\n", ft_lstlast(&head, l)->i);
	//printf("%d\n", ft_lstsize(&l, l));
	//printf("%d\n", head->i);
	return (0);
}
