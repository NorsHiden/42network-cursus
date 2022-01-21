/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 13:38:24 by marvin            #+#    #+#             */
/*   Updated: 2022/01/17 13:38:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**setup_path(char **p)
{
	size_t	i;
	char	**paths;
	char	*tmp;

	i = 0;
	while (ft_strncmp("PATH", p[i], 4) && p[i])
		i++;
	if (ft_strncmp("PATH", p[i], 4))
		raise_error(NULL, 'x');
	paths = ft_split(&p[i][5], ':');
	if (!paths)
		raise_error(NULL, 'x');
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

char	**check_path(char **cmd, char **p)
{
	char	*tmp;
	char	**paths;
	size_t	i;

	paths = setup_path(p);
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], cmd[0]);
		if (!tmp)
			raise_error(NULL, 'x');
		if (!access(tmp, X_OK))
			break ;
		free(tmp);
		i++;
	}
	free_mem(paths);
	free(cmd[0]);
	cmd[0] = tmp;
	return (cmd);
}

char	**setup_cmd(char *str, char **p)
{
	size_t	i;
	char	**cmd;

	if (!*str)
		raise_error("No such file or directory\n", 'x');
	i = 0;
	cmd = ft_split(str, ' ');
	if (!cmd)
		raise_error(NULL, 'x');
	while (cmd[0][i])
	{
		if (cmd[0][i] == '/')
		{
			if (access(cmd[0], X_OK))
				raise_error("command not found\n", 'x');
			return (cmd);
		}
		i++;
	}
	return (check_path(cmd, p));
}
