/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:48:25 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 15:41:18 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*create_stack(int len, char **arr)
{
	t_list	*a;
	t_list	*tmp;
	int		i;

	a = 0;
	i = 1;
	while (i < len)
	{
		tmp = ft_lstnew(ft_atoi(arr[i]));
		if (!tmp)
		{
			ft_lstclear(&a);
			return (NULL);
		}
		ft_lstadd_back(&a, tmp);
		i++;
	}
	return (a);
}

static void	sort_arr(int *dec, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 1;
		while (j < size)
		{
			if (dec[j - 1] > dec[j])
			{
				temp = dec[j];
				dec[j] = dec[j - 1];
				dec[j - 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	ft_stack_reedit(t_list **stacks, char **arr, int size)
{
	t_list	*a;
	int		*dec;
	int		i;

	dec = (int *)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		dec[i] = ft_atoi(arr[i]);
		i++;
	}
	sort_arr(dec, size);
	a = stacks[0];
	while (a)
	{
		i = 0;
		while (a->index != dec[i])
			i++;
		if (a->index == dec[i])
			a->index = i;
		a = a->next;
	}
	free(dec);
}
