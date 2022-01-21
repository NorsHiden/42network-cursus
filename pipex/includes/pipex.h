/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:18:03 by marvin            #+#    #+#             */
/*   Updated: 2022/01/15 17:18:03 by marvin           ###   ########.fr       */
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
# include "../libft/libft.h"

# define BUFFER_SIZE 1024

/*____________MANDATORY____________*/

void	first_process(int *fdp, int infile, char **v, char **p);
void	second_process(int *fdp, char **v, char **p);
int		outfile_c(char *path);

/*______________TOOLS______________*/

char	**setup_path(char **p);
char	**setup_cmd(char *str, char **p);
void	free_mem(char **str);
void	raise_error(char *error, char x);

/*______________BONUS______________*/

char	*get_next_line(int fd);
void	run_process(char *cmd, char **p);
void	child_process(int	*fdp, char *fullcmd, char **p);
void	out_process(char *here_doc, char *fullcmd, char *outfile, char **p);

#endif