/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:17:22 by marvin            #+#    #+#             */
/*   Updated: 2022/01/15 17:17:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	outfile_c(char *path)
{
	int	fd;

	if (access(path, F_OK) == 0)
	{
		if (unlink(path) == -1)
			raise_error(NULL, 'x');
	}
	fd = open(path, O_WRONLY | O_CREAT, 0777);
	return (fd);
}

int	main(int c, char **v, char **p)
{
	int		fdp[2];
	int		infile;
	pid_t	pid;

	if (c != 5)
		raise_error("Error\n", 'x');
	pipe(fdp);
	if (access(v[1], R_OK) == -1)
	{
		close(outfile_c(v[4]));
		raise_error("No such file or directory\n", 'x');
	}
	infile = open(v[1], O_RDONLY);
	pid = fork();
	if (pid == -1)
		raise_error(NULL, 'x');
	if (pid == 0)
		first_process(fdp, infile, v, p);
	waitpid(pid, NULL, 0);
	second_process(fdp, v, p);
	return (0);
}
