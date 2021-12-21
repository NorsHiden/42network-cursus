/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 09:48:01 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 14:14:55 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list	*a)
{
	while (a->next)
	{
		if (a->index > a->next->index)
			return (0);
		a = a->next;
	}
	return (1);
}

int	index_pos(t_list *a, int num)
{
	int	i;

	i = 1;
	while (a->index != num && a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

int	fetch_num(t_list *a, char c)
{
	int	num;

	num = a->index;
	while (a)
	{
		if (c == 's')
		{
			if (num > a->index)
				num = a->index;
		}
		else
		{
			if (num < a->index)
				num = a->index;
		}
		a = a->next;
	}
	return (num);
}

int	before_last(t_list *a, int smallnum, int largenum)
{
	int	num;

	num = smallnum;
	while (a)
	{
		if (a->index > num && a->index != largenum)
			num = a->index;
		a = a->next;
	}
	return (num);
}
