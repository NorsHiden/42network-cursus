/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 21:28:29 by nelidris          #+#    #+#             */
/*   Updated: 2021/11/04 18:23:46 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(str);
	while (i)
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i--;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}
