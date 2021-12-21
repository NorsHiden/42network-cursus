/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:29:25 by nelidris          #+#    #+#             */
/*   Updated: 2021/11/23 17:59:40 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = ft_strlen(str);
	return (write(1, str, i));
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] && (unsigned char)s1[i] == (unsigned char)s2[i]
		&& i + 1 < n)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
