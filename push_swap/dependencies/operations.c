/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 10:24:16 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 14:14:50 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	e_swap(t_list *e, char c)
{
	int	tmp;

	if (!e || !e->next)
		return ;
	tmp = e->index;
	e->index = e->next->index;
	e->next->index = tmp;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
}

void	e_push(t_list **e1, t_list **e2, char c)
{
	t_list	*tmp;

	if (!(*e1))
		return ;
	tmp = *e1;
	*e1 = (*e1)->next;
	ft_lstadd_front(e2, tmp);
	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
}

void	e_rotate(t_list **e, char c)
{
	t_list	*head;

	head = *e;
	if (!head || !head->next)
		return ;
	*e = (*e)->next;
	ft_lstadd_back(e, head);
	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
}

void	e_reverse(t_list **e, char c)
{
	t_list	*prelast;

	if (!*e || !(*e)->next)
		return ;
	prelast = *e;
	while (prelast->next->next)
		prelast = prelast->next;
	ft_lstadd_front(e, prelast->next);
	prelast->next = 0;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
}
