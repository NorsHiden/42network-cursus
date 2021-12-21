/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 11:23:52 by nelidris          #+#    #+#             */
/*   Updated: 2021/11/02 16:18:52 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char*dest, const char*src, size_t dstsize)
{
	size_t	i;
	size_t	srcsize;

	srcsize = ft_strlen(src);
	if (dstsize == 0)
		return (srcsize);
	i = 0;
	while (src[i] && (i + 1 < dstsize))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srcsize);
}
