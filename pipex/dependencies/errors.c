/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 17:17:20 by marvin            #+#    #+#             */
/*   Updated: 2022/01/15 17:17:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	raise_error(char *error, char x)
{
	if (!error)
		perror(NULL);
	else
		ft_putstr_fd(error, 2);
	if (x == 'x')
		exit(1);
	if (x == 'e')
		exit(127);
}

void	free_mem(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
