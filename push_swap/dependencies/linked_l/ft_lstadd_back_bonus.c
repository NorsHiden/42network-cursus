/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:41:23 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 14:15:00 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *e)
{
	t_list	*ptr;

	if (!*lst)
	{
		*lst = e;
		return ;
	}
	ptr = ft_lstlast(*lst);
	ptr->next = e;
	e->next = 0;
}
