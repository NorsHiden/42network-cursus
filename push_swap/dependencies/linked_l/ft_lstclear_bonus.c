/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:41:10 by nelidris          #+#    #+#             */
/*   Updated: 2021/12/21 14:31:51 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*ptr;
	t_list	*frp;

	ptr = *lst;
	if (!*lst)
		return ;
	while (ptr)
	{
		frp = ptr;
		ptr = ptr->next;
		free(frp);
	}
	*lst = 0;
}
