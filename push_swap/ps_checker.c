/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:48:45 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 15:40:52 by nelidris         ###   ########.fr       */
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
	read_instructions(stacks);
	return (0);
}
