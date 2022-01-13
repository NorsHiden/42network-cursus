/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 15:23:52 by nelidris          #+#    #+#             */
/*   Updated: 2021/11/08 11:28:32 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*_fill_buff_itoa(int n, char *number, int cc)
{
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_memcpy(number, "-2147483648", 11));
		number[0] = '-';
		return (_fill_buff_itoa((n * -1), number, cc));
	}
	else if (n > 9)
	{
		_fill_buff_itoa((n / 10), number, cc - 1);
		number[cc] = (n % 10) + 48;
		return (number);
	}
	else
		number[cc] = n + 48;
	return (number);
}

static	size_t	_num_count(int n)
{
	size_t	cc;

	cc = 0;
	while (n)
	{
		n /= 10;
		cc++;
	}
	return (cc);
}

char	*ft_itoa(int n)
{
	size_t	cc;
	char	*number;

	cc = _num_count(n);
	if (n <= 0)
		cc++;
	number = (char *)malloc(cc + 1);
	if (!number)
		return (NULL);
	number = _fill_buff_itoa(n, number, cc - 1);
	number[cc] = '\0';
	return (number);
}
