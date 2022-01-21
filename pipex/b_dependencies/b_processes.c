/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_processes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 22:05:52 by marvin            #+#    #+#             */
/*   Updated: 2022/01/17 22:05:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	out_process(char *here_doc, char *fullcmd, char *outfile, char **p)
{
	char	**cmd;
	int		fd;

	if (!ft_strncmp("here_doc", here_doc, ft_strlen(here_doc)))
		fd = open(outfile, O_CREAT | O_WRONLY | O_APPEND, 0777);
	else
	{
		if (!access(outfile, W_OK))
			unlink(outfile);
		fd = open(outfile, O_CREAT | O_WRONLY, 0777);
	}
	dup2(fd, 1);
	close(fd);
	cmd = setup_cmd(fullcmd, p);
	if (execve(cmd[0], cmd, p) == -1)
		raise_error("command not found\n", 'e');
}

void	child_process(int	*fdp, char *fullcmd, char **p)
{
	char	**cmd;

	cmd = setup_cmd(fullcmd, p);
	dup2(fdp[1], 1);
	close(fdp[1]);
	close(fdp[0]);
	if (execve(cmd[0], cmd, p) == -1)
		raise_error("command not found\n", 'e');
}

void	run_process(char *cmd, char **p)
{
	int		fdp[2];
	pid_t	pid;

	if (pipe(fdp) == -1)
		raise_error(NULL, 'x');
	pid = fork();
	if (pid == -1)
		raise_error(NULL, 'x');
	if (pid == 0)
		child_process(fdp, cmd, p);
	dup2(fdp[0], 0);
	close(fdp[0]);
	close(fdp[1]);
	waitpid(pid, NULL, 0);
}
