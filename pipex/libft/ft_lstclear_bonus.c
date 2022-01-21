/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nelidris <nelidris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 20:41:10 by nelidris          #+#    #+#             */
/*   Updated: 2021/11/08 20:41:12 by nelidris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*frp;

	ptr = *lst;
	if (!*lst || !del)
		return ;
	while (ptr)
	{
		frp = ptr;
		ptr = ptr->next;
		ft_lstdelone(frp, del);
	}
	*lst = 0;
}
