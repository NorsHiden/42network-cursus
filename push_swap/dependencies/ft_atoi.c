/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:53:51 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 14:14:38 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long	_convert(const	char *str, long sign)
{
	size_t	i;
	size_t	rslt;

	i = 0;
	rslt = 0;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (rslt * 10 + (str[i] - 48)
			> 2147483647 && sign == 1)
			return (2147483648);
		else if (rslt * 10 + (str[i] - 48)
			> 2147483648 && sign == -1)
			return (2147483648);
		rslt = (rslt * 10) + (str[i] - 48);
		i++;
	}
	if (str[i])
		return (2147483648);
	return (rslt * sign);
}

long	ft_atoi(const char *str)
{
	size_t	i;
	long	sign;

	i = 0;
	sign = 1;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!str[i])
		return (2147483648);
	return (_convert(&str[i], sign));
}
