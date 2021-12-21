/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:53:51 by nelidris          #+#    #+#             */
/*   Updated: 2021/11/07 11:32:34 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_convert(const	char *str, int sign)
{
	size_t	i;
	size_t	rslt;

	i = 0;
	rslt = 0;
	while (str[i] && ft_isdigit(str[i]))
	{
		if ((unsigned long)rslt * 10 + (str[i] - 48)
			> 9223372036854775807 && sign == 1)
			return (-1);
		else if ((unsigned long)rslt * 10 + (str[i] - 48)
			> (unsigned long)9223372036854775807 + 1 && sign == -1)
			return (0);
		rslt = (rslt * 10) + (str[i] - 48);
		i++;
	}
	return ((long)rslt * sign);
}

int	ft_atoi(const char *str)
{
	size_t			i;
	int				sign;

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
	return (_convert(&str[i], sign));
}
