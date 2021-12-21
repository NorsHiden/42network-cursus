/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:43:20 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 14:14:40 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dptr;
	const unsigned char	*sptr;

	dptr = (unsigned char *)dst;
	sptr = (unsigned char *)src;
	if (!dptr && !sptr)
		return (NULL);
	while (n--)
	{
		*dptr = *sptr;
		dptr++;
		sptr++;
	}
	return (dst);
}
