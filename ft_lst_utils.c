/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 14:57:05 by abayar            #+#    #+#             */
/*   Updated: 2022/03/19 16:27:04 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dellst(t_list *l)
{
	int		i;
	t_list	*temp;

	i = l->i;
	temp = l;
	while (l->next->i != i)
	{
		l = l->next;
	}
	if (l->next->i != l->i)
	{
		temp = l->next;
		l->next = l->next->next;
		free(temp);
		temp = NULL;
	}
	else
	{
		free(l);
		l = NULL;
		return ;
	}
}
