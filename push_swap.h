/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:35:15 by abayar            #+#    #+#             */
/*   Updated: 2022/02/14 20:15:10 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct s_list
{
	int				i;
	struct s_list	*next;
}	t_list;

void	ft_lstadd_back(t_list **alst, int data);
void	ft_lstadd_front(t_list **alst, int data);
t_list	*ft_lstlast(t_list **head, t_list *lst);
t_list	*ft_lstnew(int content);
int		ft_lstsize(t_list **head, t_list *lst);
int	ft_atoi(const char *str);

#endif