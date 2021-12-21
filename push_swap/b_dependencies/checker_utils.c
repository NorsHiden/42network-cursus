/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 11:11:45 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 15:27:01 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	_ss(char *ops, t_list **stacks)
{
	if (!ft_strncmp(ops, "sa", 2))
		e_swap(stacks[0], 'c');
	else if (!ft_strncmp(ops, "sb", 2))
		e_swap(stacks[1], 'c');
	else if (!ft_strncmp(ops, "ss", 2))
	{
		e_swap(stacks[0], 'c');
		e_swap(stacks[1], 'c');
	}
}

static void	_rrr(char *ops, t_list **stacks)
{
	if (!ft_strncmp(ops, "rra", 3))
		e_reverse(&stacks[0], 'c');
	else if (!ft_strncmp(ops, "rrb", 3))
		e_reverse(&stacks[1], 'c');
	else if (!ft_strncmp(ops, "rrr", 3))
	{
		e_reverse(&stacks[0], 'c');
		e_reverse(&stacks[1], 'c');
	}
}

static void	_rr(char *ops, t_list **stacks)
{
	if (!ft_strncmp(ops, "ra", 2))
		e_rotate(&stacks[0], 'c');
	else if (!ft_strncmp(ops, "rb", 2))
		e_rotate(&stacks[1], 'c');
	else if (!ft_strncmp(ops, "rr", 2))
	{
		e_rotate(&stacks[0], 'c');
		e_rotate(&stacks[1], 'c');
	}
}

static void	_pp(char *ops, t_list **stacks)
{
	if (!ft_strncmp(ops, "pa", 2))
		e_push(&stacks[1], &stacks[0], 'c');
	else if (!ft_strncmp(ops, "pb", 2))
		e_push(&stacks[0], &stacks[1], 'c');
}

void	read_instructions(t_list **stacks)
{
	char	*ops;

	ops = get_next_line(0);
	while (ops)
	{
		if (!ft_strncmp(ops, "sa", 2) || !ft_strncmp(ops, "sb", 2)
			|| !ft_strncmp(ops, "ss", 2))
			_ss(ops, stacks);
		else if (!ft_strncmp(ops, "rra", 3) || !ft_strncmp(ops, "rrb", 3)
			|| !ft_strncmp(ops, "rrr", 3))
			_rrr(ops, stacks);
		else if (!ft_strncmp(ops, "ra", 2) || !ft_strncmp(ops, "rb", 2)
			|| !ft_strncmp(ops, "rr", 2))
			_rr(ops, stacks);
		else if (!ft_strncmp(ops, "pa", 2) || !ft_strncmp(ops, "pb", 2))
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
