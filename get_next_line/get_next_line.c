/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:55:21 by nelidris          #+#    #+#             */
/*   Updated: 2021/11/18 19:13:09 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	_freemem(char **ptr)
{
	free(*ptr);
	*ptr = 0;
}

static char	*ft_the_line(char **pal)
{
	char	*line;
	char	*temp;
	size_t	i;

	i = 0;
	while ((*pal)[i] && (*pal)[i] != '\n')
		i++;
	if ((*pal)[i] == '\n')
	{
		line = ft_substr(*pal, 0, i + 1);
		temp = *pal;
		*pal = ft_strjoin(&(*pal)[i + 1], "");
		_freemem(&temp);
	}
	else
	{
		line = ft_strjoin(*pal, "");
		_freemem(pal);
	}
	if (*line == '\0')
		_freemem(&line);
	return (line);
}

static char	*ft_array(int fd, char **pal, char **hndlr)
{
	char	*bigsize;
	ssize_t	re;

	re = 1;
	while (re && !ft_strchr(*pal, '\n'))
	{
		re = read(fd, *hndlr, BUFFER_SIZE);
		(*hndlr)[re] = 0;
		bigsize = *pal;
		*pal = ft_strjoin(*pal, *hndlr);
		_freemem(&bigsize);
	}
	_freemem(hndlr);
	return (ft_the_line(pal));
}

char	*get_next_line(int fd)
{
	static char	*pal = NULL;
	char		*hndlr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	hndlr = (char *)malloc(BUFFER_SIZE + 1);
	if (!hndlr)
		return (NULL);
	if (read(fd, hndlr, 0) < 0)
	{
		_freemem(&hndlr);
		return (NULL);
	}
	if (!pal)
		pal = ft_strjoin("", "");
	return (ft_array(fd, &pal, &hndlr));
}
