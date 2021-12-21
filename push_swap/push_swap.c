/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:49:50 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 15:41:09 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int c, char **v)
{
	t_list	**stacks;

	if (c < 2)
		return (0);
	if (is_error(c, v))
		raise_error();
	stacks = (t_list **)malloc(sizeof(t_list *) * 2);
	if (!stacks)
		return (1);
	stacks[0] = create_stack(c, v);
	stacks[1] = 0;
	if (c - 1 <= 3)
		sort_stack_3(stacks, c - 1);
	else if (c - 1 <= 5)
		sort_stacks_5(stacks, c - 1);
	else
	{
		ft_stack_reedit(&stacks[0], &v[1], c - 1);
		sort_stack_radix(stacks, c - 1);
	}
	return (0);
}
