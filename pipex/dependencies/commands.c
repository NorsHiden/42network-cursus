/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:34:13 by marvin            #+#    #+#             */
/*   Updated: 2022/01/13 17:34:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_command(t_pipex *pl, char **envp)
{
	int	fd;

	fd = open(pl->infile, O_RDONLY);
	dup2(fd, 0);
	close(fd);
	dup2(pl->pfd[1], 1);
	close(pl->pfd[0]);
	close(pl->pfd[1]);
	execve(pl->cmd1[0], pl->cmd1, envp);
	raise_error(NULL);
}

void	second_command(t_pipex *pl, char **envp)
{
	int	fd;

	if (access(pl->outfile, F_OK))
		fd = open(pl->outfile, O_WRONLY | O_CREAT, 0777);
	else
		fd = open(pl->outfile, O_WRONLY);
	dup2(pl->pfd[0], 0);
	close(pl->pfd[0]);
	close(pl->pfd[1]);
	dup2(fd, 1);
	close(fd);
	execve(pl->cmd2[0], pl->cmd2, envp);
	raise_error(NULL);
}
