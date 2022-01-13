/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:25:23 by marvin            #+#    #+#             */
/*   Updated: 2022/01/11 23:25:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int c, char **v, char **p)
{
	t_pipex	pl;

	if (c < 5)
		raise_error("Please enter the args as follows:"
			" ./pipex [infile] [cmd1] [cmd2] [outfile]\n");
	setup_pipe(&pl, v, p);
	pl.pid1 = fork();
	if (pl.pid1 == 0)
		first_command(&pl, p);
	else
		waitpid(pl.pid1, NULL, 0);
	pl.pid2 = fork();
	if (pl.pid2 == 0)
		second_command(&pl, p);
	else
	{
		close(pl.pfd[0]);
		close(pl.pfd[1]);
		waitpid(pl.pid2, NULL, 0);
	}
	return (0);
}
