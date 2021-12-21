/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 09:42:43 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 14:14:51 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_error(int c, char **arr)
{
	int	i;
	int	j;

	i = 1;
	while (i < c)
	{
		if (ft_atoi(arr[i]) == 2147483648)
			return (1);
		i++;
	}
	i = 1;
	while (i < c)
	{
		j = i + 1;
		while (j < c)
		{
			if (ft_atoi(arr[i]) == ft_atoi(arr[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	raise_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
