/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 11:04:24 by nelidris          #+#    #+#             */
/*   Updated: 2021/11/09 14:36:00 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	mlenf(size_t slen, unsigned int start, size_t len)
{
	if (slen - start < len)
		return (slen - start);
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	mlen;
	size_t	slen;
	char	*sub;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	i = 0;
	if (start >= slen)
	{
		sub = (char *)malloc(1);
		if (!sub)
			return (NULL);
		sub[i] = 0;
		return (sub);
	}
	mlen = mlenf(slen, start, len);
	sub = (char *)malloc(mlen + 1);
	if (!sub)
		return (NULL);
	ft_memcpy(sub, &s[start], mlen);
	sub[mlen] = '\0';
	return (sub);
}
