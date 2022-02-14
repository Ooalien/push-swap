/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abayar <abayar@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 11:26:04 by abayar            #+#    #+#             */
/*   Updated: 2022/02/14 20:14:57 by abayar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long long	checker(unsigned long long n, int signe)
{
	if (n <= 9223372036854775807)
		return (n * signe);
	if (signe < 0)
		return (0);
	return (-1);
}

int	ft_atoi(const char *str)
{
	long long	res;
	int			signe;
	int			i;

	i = 0;
	signe = 1;
	res = 0;
	while ((str[i] == ' ') || (str[i] == '\t')
		|| (str[i] == '\n') || (str[i] == '\r')
		|| (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	res = checker(res, signe);
	return (res);
}
