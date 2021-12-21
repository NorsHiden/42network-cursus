/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:31:22 by nelidris          #+#    #+#             */
/*   Updated: 2021/11/28 11:41:16 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_write_sign(char id, va_list arg)
{
	if (id == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (id == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (id == 'p')
		return (ft_print_address(va_arg(arg, void *)));
	if (id == 'd' || id == 'i')
		return (ft_putnbr_base(va_arg(arg, int), DECB));
	if (id == 'u')
		return (ft_putnbr_base_unsigned((va_arg(arg, unsigned int)), DECB));
	if (id == 'x')
		return (ft_putnbr_base(va_arg(arg, int), LHEXB));
	if (id == 'X')
		return (ft_putnbr_base(va_arg(arg, int), UHEXB));
	if (id == '%')
		return (write(1, &id, 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	size_t	i;
	int		suwr;

	va_start(arg, str);
	i = 0;
	suwr = 0;
	while (str[i])
	{
		if (str[i] == '%')
			suwr += ft_write_sign(str[++i], arg);
		else
			suwr += write(1, &str[i], 1);
		i++;
	}
	va_end(arg);
	return (suwr);
}
