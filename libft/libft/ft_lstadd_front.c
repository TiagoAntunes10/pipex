/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tialbert <tialbert@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 11:47:37 by tialbert          #+#    #+#             */
/*   Updated: 2023/10/03 11:47:38 by tialbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (current == NULL)
		*lst = new;
	else
	{
		new->next = current;
		*lst = new;
	}
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	t_list	**lst;
	t_list	*lst1;
	t_list	*lst2;
	t_list	*lst3;
	t_list	*new;
	t_list	*current;

	lst = malloc(sizeof(t_list **));
	lst1 = ft_lstnew("aaaaaa");
	ft_lstadd_front(lst, lst1);
	lst2 = ft_lstnew("bbbbbb");
	ft_lstadd_front(lst, lst2);
	lst3 = ft_lstnew("ccccccc");
	ft_lstadd_front(lst, lst3);
	new = ft_lstnew("dddddd");
	ft_lstadd_front(lst, new);
	current = *lst;
	while (current != NULL)
	{
		printf("%s\n", (char *) current->content);
		current = current->next;
	}
}*/
