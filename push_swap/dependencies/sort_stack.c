/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 10:31:59 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 14:14:53 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stack_3(t_list	**stacks, int size)
{
	int	snum;
	int	lnum;

	if (size <= 2 && !is_sorted(stacks[0]))
	{
		e_swap(stacks[0], 'a');
		return ;
	}
	snum = fetch_num(stacks[0], 's');
	lnum = fetch_num(stacks[0], 'l');
	if (!is_sorted(stacks[0]))
	{
		if (index_pos(stacks[0], lnum) == 2)
			e_reverse(&stacks[0], 'a');
		else if (index_pos(stacks[0], lnum) == 1)
			e_rotate(&stacks[0], 'a');
		if (stacks[0]->index > stacks[0]->next->index)
			e_swap(stacks[0], 'a');
	}
}

void	sort_stacks_5(t_list **stacks, int size)
{
	int	snum;
	int	lnum;

	lnum = fetch_num(stacks[0], 'l');
	snum = fetch_num(stacks[0], 's');
	while (!is_sorted(stacks[0]) || stacks[1])
	{
		if (stacks[0]->index == before_last(stacks[0], snum, lnum))
			e_rotate(&stacks[0], 'a');
		else if (stacks[0]->next->index == before_last(stacks[0], snum, lnum))
			e_reverse(&stacks[0], 'a');
		while (ft_lstsize(stacks[0]) > 3 && !is_sorted(stacks[0]->next))
			e_push(&stacks[0], &stacks[1], 'b');
		sort_stack_3(stacks, size);
		while (stacks[1])
		{
			e_push(&stacks[1], &stacks[0], 'a');
			if (stacks[0]->index > ft_lstlast(stacks[0])->index)
				e_rotate(&stacks[0], 'a');
			else if (stacks[0]->index > stacks[0]->next->index)
				e_swap(stacks[0], 'a');
		}
	}
}

void	sort_stack_radix(t_list **stacks, int size)
{
	int	bit;
	int	j;

	bit = 0;
	while (!is_sorted(stacks[0]) || stacks[1])
	{
		j = 0;
		while (j++ < size)
		{
			if (((stacks[0]->index >> bit) & 1) == 1)
			{
				e_rotate(&stacks[0], 'a');
			}
			else
				e_push(&stacks[0], &stacks[1], 'b');
		}
		while (stacks[1])
			e_push(&stacks[1], &stacks[0], 'a');
		bit++;
	}
}
