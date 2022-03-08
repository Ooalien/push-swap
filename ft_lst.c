/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 17:58:33 by abayar            #+#    #+#             */
/*   Updated: 2022/03/07 21:19:04 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int content)
{
	t_list	*l;

	l = malloc(sizeof(t_list));
	if (!l)
		return (NULL);
	l->i = content;
	l->index = 0;
	l->moves = 0;
	l->sum = 0;
	l->pos = 0;
	l->next = l;
	return (l);
}

t_list	*ft_lstlast(t_list **head, t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != *head)
		lst = lst->next;
	return (lst);
}

int	ft_lstsize(t_list **head, t_list *lst)
{
	int	i;

	i = 0;
	while (lst->next != *head)
	{
		lst = lst->next;
		i++;
	}
	i++;
	return (i);
}

void	ft_lstadd_back(t_list **alst, int data)
{
	t_list	*l;
	t_list	*new;

	new = ft_lstnew(data);
	if (!*alst)
	{
		*alst = new;
		new->next = *alst;
		return ;
	}
	l = ft_lstlast(alst, *alst);
	l->next = new;
	new->next = *alst;
}

void	ft_lstadd_front(t_list **alst, int data, int index)
{
	t_list	*temp;
	t_list	*new = ft_lstnew(data);
	
	new->index = index;
	if (!(*alst))
	{
		*alst = new;
		new->next = new;
		return ;
	}
		//return ;
	//new->next = *alst;
	//printf("%d\n", ft_lstlast(alst, *alst)->i);
	ft_lstlast(alst, *alst)->next = new;
	new->next = *alst;
	*alst = new;
	//printlst(alst, *alst);
}

void	dellst(t_list *l)
{
	int	i;
	t_list	*temp;

	i = l->i;
	l = temp;
	while (l->next->i != i)
	{
		l = l->next;
	}
	if (l->next->i != l->i)
		l->next = l->next->next;
	else
	{
		//l->i = NULL;
		l = NULL;
		free(l);
	}
	temp = NULL;
	free(temp);
	
	//l->i = NULL;
}