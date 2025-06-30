/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:33:16 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/23 22:30:06 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst == 0)
		{
			*lst = new;
			return ;
		}
	if (new == 0)
		return ;
	new->next = *lst;
	*lst = new;
}
