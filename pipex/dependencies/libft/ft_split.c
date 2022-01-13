/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:47:25 by nelidris          #+#    #+#             */
/*   Updated: 2021/11/10 14:31:51 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	_word_count(char const *s, char c)
{
	size_t	i;
	size_t	cp;

	i = 0;
	cp = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i] && s[i] != c)
			i++;
		cp++;
	}
	return (cp);
}

static int	_freemem(char **s2d, size_t level)
{
	if (s2d[level])
		return (0);
	while (level--)
		free(s2d[level]);
	return (1);
}

static void	_fillbuffer(const char *s, char c, char	**s2d)
{
	size_t	cp;
	size_t	i;
	size_t	level;

	cp = 0;
	level = 0;
	i = 0;
	while (s[i])
	{
		cp = 0;
		while (s[i] && s[i] == c)
			i++;
		if (!s[i])
			break ;
		while (s[i + cp] && s[i + cp] != c)
			cp++;
		s2d[level] = ft_substr(s, i, cp);
		if (_freemem(s2d, level))
			return ;
		i += cp;
		level++;
	}
	s2d[level] = 0;
}

char	**ft_split(char const *s, char c)
{
	char	**s2d;
	size_t	cp;

	if (!s)
		return (NULL);
	cp = _word_count(s, c);
	s2d = (char **)malloc(sizeof(char *) * (cp + 1));
	if (!s2d)
		return (NULL);
	_fillbuffer(s, c, s2d);
	if (!s2d)
		return (0);
	return (s2d);
}
