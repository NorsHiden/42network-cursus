/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:11:45 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 16:00:18 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	_ss(char *ops, t_list **stacks)
{
	if (!ft_strcmp(ops, "sa\n"))
		e_swap(stacks[0], 'c');
	else if (!ft_strcmp(ops, "sb\n"))
		e_swap(stacks[1], 'c');
	else if (!ft_strcmp(ops, "ss\n"))
	{
		e_swap(stacks[0], 'c');
		e_swap(stacks[1], 'c');
	}
}

static void	_rrr(char *ops, t_list **stacks)
{
	if (!ft_strcmp(ops, "rra\n"))
		e_reverse(&stacks[0], 'c');
	else if (!ft_strcmp(ops, "rrb\n"))
		e_reverse(&stacks[1], 'c');
	else if (!ft_strcmp(ops, "rrr\n"))
	{
		e_reverse(&stacks[0], 'c');
		e_reverse(&stacks[1], 'c');
	}
}

static void	_rr(char *ops, t_list **stacks)
{
	if (!ft_strcmp(ops, "ra\n"))
		e_rotate(&stacks[0], 'c');
	else if (!ft_strcmp(ops, "rb\n"))
		e_rotate(&stacks[1], 'c');
	else if (!ft_strcmp(ops, "rr\n"))
	{
		e_rotate(&stacks[0], 'c');
		e_rotate(&stacks[1], 'c');
	}
}

static void	_pp(char *ops, t_list **stacks)
{
	if (!ft_strcmp(ops, "pa\n"))
		e_push(&stacks[1], &stacks[0], 'c');
	else if (!ft_strcmp(ops, "pb\n"))
		e_push(&stacks[0], &stacks[1], 'c');
}

void	read_instructions(t_list **stacks)
{
	char	*ops;

	ops = get_next_line(0);
	while (ops)
	{
		if (!ft_strcmp(ops, "sa\n") || !ft_strcmp(ops, "sb\n")
			|| !ft_strcmp(ops, "ss\n"))
			_ss(ops, stacks);
		else if (!ft_strcmp(ops, "rra\n") || !ft_strcmp(ops, "rrb\n")
			|| !ft_strcmp(ops, "rrr\n"))
			_rrr(ops, stacks);
		else if (!ft_strcmp(ops, "ra\n") || !ft_strcmp(ops, "rb\n")
			|| !ft_strcmp(ops, "rr\n"))
			_rr(ops, stacks);
		else if (!ft_strcmp(ops, "pa\n") || !ft_strcmp(ops, "pb\n"))
			_pp(ops, stacks);
		else
			raise_error();
		free(ops);
		ops = get_next_line(0);
	}
	if (is_sorted(stacks[0]) && !stacks[1])
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
