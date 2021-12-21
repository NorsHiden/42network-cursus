/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 09:56:02 by nelidris          #+#    #+#             */
/*   Updated: 2021/11/09 12:42:38 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	char	*n;
	char	*h;

	n = (char *)needle;
	h = (char *)haystack;
	if (!*n)
		return (h);
	i = 0;
	while (h[i] && i < len)
	{
		if (h[i] == n[0])
		{
			if (len < ft_strlen(n) + i)
				break ;
			if (!ft_strncmp(&h[i], n, ft_strlen(needle)))
				return (&h[i]);
		}
		i++;
	}
	return (NULL);
}
