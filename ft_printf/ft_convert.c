/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:45:38 by nelidris          #+#    #+#             */
/*   Updated: 2021/11/24 13:31:31 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base_unsigned(unsigned int nbr, char *base)
{
	size_t	rt;
	size_t	b;

	b = ft_strlen(base);
	rt = 0;
	if (nbr >= b)
	{
		rt += ft_putnbr_base_unsigned((nbr / b), base);
		return (ft_putchar(base[(nbr % b)]) + rt);
	}
	else
		return (ft_putchar(base[nbr]));
}

int	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	nbr_p;
	size_t			rt;
	size_t			b;

	nbr_p = (unsigned int)nbr;
	b = ft_strlen(base);
	rt = 0;
	if (nbr < 0)
	{
		if (!ft_strncmp(base, DECB, b))
		{
			nbr_p = nbr * (-1);
			rt += ft_putchar('-');
		}
		if (nbr_p >= b)
			rt += ft_putnbr_base((nbr_p / b), base);
		return (ft_putchar(base[nbr_p % b]) + rt);
	}
	else if (nbr_p >= b)
	{
		rt += ft_putnbr_base((nbr_p / b), base);
		return (ft_putchar(base[(nbr_p % b)]) + rt);
	}
	else
		return (ft_putchar(base[nbr_p]));
}

int	ft_putnbr_address(unsigned long long nbr, char *base)
{
	size_t	rt;
	size_t	b;

	b = ft_strlen(base);
	rt = 0;
	if (nbr >= b)
	{
		rt += ft_putnbr_address((nbr / b), base);
		return (ft_putchar(base[(nbr % b)]) + rt);
	}
	else
		return (ft_putchar(base[nbr]));
}

int	ft_print_address(void *str)
{
	int	sw;

	sw = ft_putstr("0x");
	return (ft_putnbr_address((long long)str, LHEXB) + sw);
}
