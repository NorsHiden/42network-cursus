/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:17:37 by nelidris          #+#    #+#             */
/*   Updated: 2021/11/12 10:51:07 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	sum;

	sum = count * size;
	if (sum == 0)
		sum = 1;
	ptr = malloc(sum);
	if (ptr)
		ft_bzero(ptr, (sum));
	return (ptr);
}
