/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:52:37 by marvin            #+#    #+#             */
/*   Updated: 2022/01/12 20:52:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "dependencies/libft/libft.h"

typedef struct pipex_s
{
	int		pfd[2];
	char	**paths;
	char	**cmd1;
	char	**cmd2;
	char	*infile;
	char	*outfile;
	pid_t	pid1;
	pid_t	pid2;
}	t_pipex;

void	valid_infile(char *path);

char	**setup_path(char **p);
char	**setup_cmd(char *str, char **paths);
void	setup_pipe(t_pipex *pl, char **v, char **p);

void	first_command(t_pipex *pl, char **envp);
void	second_command(t_pipex *pl, char **envp);

void	raise_error(const char *error);

#endif