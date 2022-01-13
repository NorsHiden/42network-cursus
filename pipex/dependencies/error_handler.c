/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 21:02:54 by marvin            #+#    #+#             */
/*   Updated: 2022/01/12 21:02:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	valid_infile(char *path)
{
	if (access(path, F_OK))
		raise_error(NULL);
}

void	raise_error(const char *error)
{
	if (!error)
		perror("\033[0;31mError\033[0;37m");
	else
	{
		write(2, "\033[0;31mError:\033[0;37m ", 22);
		write(2, error, ft_strlen(error));
	}
	exit(1);
}
