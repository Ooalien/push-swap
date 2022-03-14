/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:35:15 by abayar            #+#    #+#             */
/*   Updated: 2022/03/14 15:04:58 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				i;
	int				index;
	int				sum;
	int				pos;
	int				moves;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **alst, int data);
void	ft_lstadd_front(t_list **alst, int data, int index);
t_list	*ft_lstlast(t_list **head, t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list **head, t_list *lst);
void	swap_a(t_list *l);
int		ft_atoi(const char *str);
void	mark_index(t_list **head, t_list *l);
void	push_b(t_list **head, t_list **head2);
void	push_a(t_list **head, t_list **head2);
void	retate_a(t_list **head);
void	rretate_a(t_list **head);
void	retate_b(t_list **head);
void	rretate_b(t_list **head);
void	retate(t_list **head);
void	rretate(t_list **head);
void	printlst(t_list **head, t_list *l);
void	dellst(t_list *l);
void	indexing(t_list **head);
int		count(t_list *l2, int i);
void	get_first_step(t_list **head, t_list **head2, int ac);
int		lst_chr(t_list **head, int index);
int		scan_moves(t_list **head, int index);
void	calc_move(t_list **head);
int		select_pair(t_list **head, int index);
int		pick_move(t_list **head, t_list **head2);
void	final_step(t_list **head, t_list **head2);
void	pos_list(t_list **head);
void	small_top(t_list **head);
int		pos_nod(t_list **head, int index);
int		pos_nod_utils(t_list **head, int sum);
void	three_numbers(t_list **head);
void	for_numbers(t_list **head, t_list **head2);
void	five_numbers(t_list **head, t_list **head2);
int		check_args(char **av);
int		is_num(char *s);
int		check_rep(char **av);
int		ft_strcmp(char *s1, char *s2);
void	two_numbers(t_list **h);
void	small_top_utils(t_list **head, int p);
void	pick_utils(t_list **head, t_list **head2);

#endif