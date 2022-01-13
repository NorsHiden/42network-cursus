/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 15:08:50 by marvin            #+#    #+#             */
/*   Updated: 2022/01/13 15:08:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**setup_path(char **p)
{
	size_t	i;
	char	**paths;
	char	*tmp;

	i = 0;
	while (ft_strncmp("PATH", p[i], 4) != 0 && p[i])
		i++;
	if (ft_strncmp("PATH", p[i], 4) != 0)
		raise_error(NULL);
	paths = ft_split(p[i], ':');
	if (!paths)
		raise_error(NULL);
	i = 0;
	while (paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(paths[i], "/");
		free(tmp);
		i++;
	}
	return (paths);
}

char	**setup_cmd(char *str, char **paths)
{
	size_t	i;
	char	**cmd;
	char	*tmp;

	if (!*str)
		raise_error("No such file or directory\n");
	i = 0;
	cmd = ft_split(str, ' ');
	if (!cmd)
		raise_error(NULL);
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], cmd[0]);
		if (!tmp)
			raise_error(NULL);
		if (!access(tmp, F_OK))
			break ;
		free(tmp);
		i++;
	}
	if (access(tmp, F_OK))
		raise_error(NULL);
	free(cmd[0]);
	cmd[0] = tmp;
	return (cmd);
}

void	setup_pipe(t_pipex *pl, char **v, char **p)
{
	if (access(v[1], F_OK))
		raise_error(NULL);
	pl->infile = v[1];
	pl->paths = setup_path(p);
	pl->cmd1 = setup_cmd(v[2], pl->paths);
	pl->cmd2 = setup_cmd(v[3], pl->paths);
	pl->outfile = v[4];
	pipe(pl->pfd);
}
