/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 13:07:05 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/19 11:25:59 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1len;
	size_t	s2len;
	size_t	i;
	size_t	k;
	char	*nstr;

	if (!s1 || !s2)
		return (0);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	k = 0;
	nstr = (char *)malloc(s1len + s2len + 1);
	if (!nstr)
		return (NULL);
	while (s1[k])
		nstr[i++] = s1[k++];
	k = 0;
	while (s2[k])
		nstr[i++] = s2[k++];
	nstr[i] = '\0';
	return (nstr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*str;

	str = (char *)s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}
