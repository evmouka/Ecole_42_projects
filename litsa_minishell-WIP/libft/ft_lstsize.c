/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evmouka <evmouka@student.42london.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:53:25 by evmouka           #+#    #+#             */
/*   Updated: 2023/11/27 19:35:12 by evmouka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int
	ft_lstsize(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
int main()
{
	t_list	*lst1;
	char	*str1 = "Hello, world!";
	t_list	*lst2 = ft_lstnew((void *)str1);
	int		i;
	lst1 = ft_lstnew(str1);
	ft_lstadd_back(&lst1, (t_list *)str1);
	ft_lstsize(lst1);
	printf("%d\n", i);
	return 0;
}
*/