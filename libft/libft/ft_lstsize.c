/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 21:09:23 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/06 21:09:25 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*
#include <stdio.h>

int	main(void)
{
	t_list	**lst;
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;
	t_list	*new;

	lst = malloc(sizeof(t_list **));
	lst1 = ft_lstnew("aaaaaa");
	ft_lstadd_front(lst, lst1);
	lst2 = ft_lstnew("bbbbbb");
	ft_lstadd_front(lst, lst2);
	lst3 = ft_lstnew("ccccccc");
	ft_lstadd_front(lst, lst3);
	new = ft_lstnew("dddddd");
	ft_lstadd_front(lst, new);
	printf("Size: %d\n", ft_lstsize(*lst));
}*/
