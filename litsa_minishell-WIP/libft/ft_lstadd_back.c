/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 17:10:42 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/23 22:44:31 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == 0)
		{
			*lst = new;
			return ;
		}
	if (!new)
		return ;
	last = ft_lstlast(*lst);
	last->next = new;
}
